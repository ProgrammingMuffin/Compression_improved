#include <iostream>
#include "compress.h"
#include "manipulate.h"

std::string input = "KEBABBRO";

int main( )
{
  int i, n, count[100];
  std::string unique;
  unique = GetUnique(input);
  GetCount(input, count, unique);
  n = (int)unique.length();
  ROOTSUM = GetROOTSUM(unique, count);
  InitLeaves(unique, count);
  std::cout<<"initialized leaves"<<std::endl;
  PrintLeaves(LEAF, LEAF_TOP);
  InjectPool();
  std::cout<<"Injected into node pool"<<std::endl;
  PrintLeaves(NODE_POOL, POOL_TOP);
  SortPool(NODE_POOL, POOL_TOP);
  std::cout<<"Sorted node pool"<<std::endl;
  PrintLeaves(NODE_POOL, POOL_TOP);
  CombineNodes();
  std::cout<<"Combined first two nodes"<<std::endl;
  PrintLeaves(LEAF, LEAF_TOP);
  RefillPool();
  std::cout<<"Refilled node pool"<<std::endl;
  PrintLeaves(NODE_POOL, POOL_TOP);
  return 0;
}
