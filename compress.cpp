#include<iostream>
#include "compress.h"

NODE LEAF[128];
NODE NODE_POOL[256];
NODE DELETED[256];
int LEAF_TOP = 0;
int POOL_TOP = 0;
int DEL_TOP = 0;

void InitLeaves(std::string input, int count[]) 
{
  int i;
  for(i=0;i<(int)input.length();i++)
  {
    LEAF[i].current = input[i];
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
