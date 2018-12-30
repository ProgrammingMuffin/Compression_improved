#include<iostream>
#include "compress.h"

NODE LEAF[128];
NODE NODE_POOL[256];
int DELETED[256];
int LEAF_TOP = 0;
int POOL_TOP = 0;
int DEL_TOP = 0;

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
    std::cout<<"Leaf "<<i+1<<": "<<input[i].current<<", "<<input[i].freq<<std::endl;
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

void CombineNodes()
{
  NODE v; //intermediate vertex/node.
  int current1, current2; //indices of the current node.
  if(NODE_POOL[0].freq != ROOTSUM) //it isn't the root.
  {
    v.freq = NODE_POOL[0].freq + NODE_POOL[1].freq;
    LEAF[LEAF_TOP] = v;
    v.current = LEAF_TOP;
    current1 = NODE_POOL[0].current;
    current2 = NODE_POOL[1].current;
    LEAF[current1].subtree = 0;
    LEAF[current2].subtree = 1;
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
    /*do something*/
  }
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