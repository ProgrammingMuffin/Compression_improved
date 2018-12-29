#include<iostream>
#include "compress.h"

NODE LEAF[128];
NODE NODE_POOL[256];
int LEAF_TOP;
int POOL_TOP;

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

void PrintLeaves(int n)
{
  int i;
  for(i=0;i<n;i++)
  {
    std::cout<<"Leaf "<<i+1<<": "<<LEAF[i].current<<", "<<LEAF[i].freq<<std::endl;
  }
}
