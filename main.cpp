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
  //std::cout<<"initialized leaves"<<std::endl;
  //PrintLeaves(LEAF, LEAF_TOP);
  InjectPool();
  //std::cout<<"Injected into node pool"<<std::endl;
  //PrintLeaves(NODE_POOL, POOL_TOP);
  SortPool(NODE_POOL, POOL_TOP);
  std::cout<<"Sorted node pool"<<std::endl;
  PrintLeaves(NODE_POOL, POOL_TOP);
  GenerateTree();
  ObtainPrefix((int)unique.length());
  PrintPrefix();
  /*std::cout<<"Building tree.."<<std::endl;
  std::cout<<"LEAF array: "<<std::endl;
  PrintLeaves(LEAF, LEAF_TOP);
  std::cout<<"ROOT_NODE values: "<<std::endl;
  std::cout<<"Current: "<<ROOT_NODE.current<<"  Freq: "<<ROOT_NODE.freq<<std::endl;*/
  return 0;
}
