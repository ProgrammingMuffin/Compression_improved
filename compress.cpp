#include<iostream>
#include "compress.h"
#include "manipulate.h"
#include "storage.h"

NODE LEAF[128];
NODE NODE_POOL[256];
NODE ROOT_NODE;
int DELETED[256];
int LEAF_TOP = 0;
int POOL_TOP = 0;
int DELETED_TOP = 0;
int ROOTSUM;

std::string PREFIX[130];
int PREFIX_TOP;

void InitLeaves(std::string input, int count[]) 
{
  int i;
  for(i=0;i<(int)input.length();i++)
  {
    LEAF[i].current = i;
    LEAF[i].freq = count[i];
  }
  LEAF_TOP = i;
}

void InjectPool() //based on deleted nodes and leaf[] it injects
{
  int t = LEAF_TOP;
  while(t != 0)
  {
    NODE_POOL[POOL_TOP] = LEAF[POOL_TOP];
    POOL_TOP++;
    t--;
  }
  std::cout<<"Injected NODE_POOL"<<std::endl;
}

void PrintLeaves(NODE input[], int n)
{
  int i;
  for(i=0;i<n;i++)
  {
    std::cout<<"Leaf "<<i<<": "<<input[i].subtree<<", ";
    std::cout<<input[i].parent<<", "<<input[i].current<<", "<<input[i].freq<<std::endl;
  }
}

void SortPool(NODE input[], int n) 
{
  int i, j;
  NODE temp;
  for(i=0;i<n;i++)
  {
    for(j=0;j<(n-i-1);j++)
    {
      if(input[j].freq > input[j+1].freq)
      {
        temp = input[j];
        input[j] = input[j+1];
        input[j+1] = temp;
      }
    }
  }
}

int CombineNodes()
{
  NODE v; //intermediate vertex/node.
  int current1, current2; //indices of the current node.
  if(NODE_POOL[0].freq != ROOTSUM) //it isn't the root.
  {
    v.freq = NODE_POOL[0].freq + NODE_POOL[1].freq;
    v.current = LEAF_TOP;
    LEAF[LEAF_TOP] = v;
    std::cout<<"intermediate current is "<<LEAF_TOP<<std::endl;
    current1 = NODE_POOL[0].current;
    current2 = NODE_POOL[1].current;
    if(LEAF[current1].freq <= LEAF[current2].freq)
    {
      LEAF[current1].subtree = 0;
      LEAF[current2].subtree = 1;
    }
    else
    {
      LEAF[current1].subtree = 1;
      LEAF[current2].subtree = 0;
    }
    //std::cout<<"CURRENT 1: "<<current1<<"  CURRENT 2: "<<current2<<std::endl;
    LEAF[current1].parent = LEAF_TOP;
    LEAF[current2].parent = LEAF_TOP;
    DELETED[DELETED_TOP] = current1;
    DELETED_TOP++;
    DELETED[DELETED_TOP] = current2;
    DELETED_TOP++;
    LEAF_TOP++;
  }
  else
  {
    ROOT_NODE.current = NODE_POOL[0].current;
    ROOT_NODE.freq = NODE_POOL[0].freq;
    //ROOT_NODE.subtree = -1;
    return NODE_POOL[0].current;
  }
  return 0;
}

void RefillPool()
{
  int i=0, j=0, t;
  ClearPool();
  t = LEAF_TOP;
  while(t != 0)
  {
    for(i=0;i<DELETED_TOP;i++)
    {
      if(LEAF[j].current == DELETED[i])
        break;
    }
    if(i == DELETED_TOP) //j is not a deleted vertex
    {
      NODE_POOL[POOL_TOP] = LEAF[j];
      POOL_TOP++;
    }
    else
    {
      /*do something*/
    }
    j++;
    t--;
  }
  SortPool(NODE_POOL, POOL_TOP);
}

void GenerateTree()
{
  int t;
  t = CombineNodes();
  RefillPool();
  while(t == 0)
  {
    t = CombineNodes();
    RefillPool();
    std::cout<<"NODE_POOL array (iteration "<<t<<"): "<<std::endl;
    PrintLeaves(LEAF, LEAF_TOP);
  }
}


void ObtainPrefix(int n)
{
  int i, t, next;
  char c;
  std::string temp;
  PREFIX_TOP = 0;
  for(i=0;i<n;i++)
  {
    next = i;
    while(LEAF[next].freq != ROOTSUM)
    {
      if(LEAF[next].subtree == 0)
        c = '0';
      else
        c = '1';
      temp.push_back(c);
      t = LEAF[next].parent;
      next = t;
    }//
    std::cout<<"CHECK: frequency: "<<LEAF[next].freq<<std::endl;
    PREFIX[PREFIX_TOP] = temp;
    PREFIX_TOP++;
    temp.clear();
  }
}

void PrintPrefix()
{
  int i;
  PrintLeaves(LEAF, LEAF_TOP);
  for(i=0;i<PREFIX_TOP;i++)
  {
    std::cout<<"Prefix of "<<i<<", freq: "<<LEAF[i].freq<<" is "<<PREFIX[i]<<std::endl;
  }
}

void ResolveOutput(std::string unique)
{
  int i, j, pos;
  std::string temp;
  for(i=0;i<(int)input.length();i++)
  {
    pos = GetCharPos(input[i], unique);
    std::cout<<"POS IS: "<<pos<<std::endl;
    if(pos >= 0)
    {
      temp = PREFIX[pos];
      for(j=(int)temp.length()-1;j>=0;j--)
      {
        if(temp[j] == '0')
          PushBuffer(0);
        else
          PushBuffer(1);
      }
    }
    else
    {
      /*Handle this error*/
    }
    temp.clear();
  }
  OUTPUT.push_back(PREV_SIZE);
}

void PrintOutput()
{
  //std::cout<<"The output is: "<<OUTPUT<<std::endl;
  int i;
  for(i=0;i<(int)OUTPUT.length();i++)
  {
    std::cout<<"The output is: "<<(int)OUTPUT[i]<<"  ";
  }
  std::cout<<std::endl;
}