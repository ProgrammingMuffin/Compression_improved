#include <iostream>
#include "compress.h"
#include "manipulate.h"

std::string input = "KEBABBRO";

int main( )
{
  int i, n, count[100], t;
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
  /*CombineNodes();
  std::cout<<"Combined first two nodes"<<std::endl;
  PrintLeaves(LEAF, LEAF_TOP);
  RefillPool();
  std::cout<<"Refilled node pool"<<std::endl;
  PrintLeaves(NODE_POOL, POOL_TOP);*/
  t = CombineNodes();
  RefillPool();
  //std::cout<<"ATTENTION! t = "<<t<<std::endl;
  //std::cout<<"LEAF_POOL array (iteration "<<t<<"): "<<std::endl;
  PrintLeaves(LEAF, LEAF_TOP);
  while(t == 0)
  {
    t = CombineNodes();
    RefillPool();
    //std::cout<<"LEAF_POOL array (iteration "<<t<<"): "<<std::endl;
    //PrintLeaves(LEAF, LEAF_TOP);
  }
  //std::cout<<"Building tree.."<<std::endl;
  //std::cout<<"LEAF array: "<<std::endl;
  //PrintLeaves(LEAF, LEAF_TOP);
  //std::cout<<"NODE_POOL array: "<<std::endl;
  //PrintLeaves(NODE_POOL, POOL_TOP);
  //std::cout<<"ROOT_NODE values: "<<std::endl;
  //std::cout<<"Current: "<<ROOT_NODE.current<<"  Freq: "<<ROOT_NODE.freq<<std::endl;
  //std::cout<<"ROOTSUM = "<<ROOTSUM<<std::endl;  
  return 0;
}
