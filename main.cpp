#include <iostream>
#include "compress.h"
#include "manipulate.h"
#include "storage.h"

namespace std
{
  typedef basic_string<unsigned char> unstring;
}

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
  InjectPool();
  SortPool(NODE_POOL, POOL_TOP);
  std::cout<<"Sorted node pool"<<std::endl;
  PrintLeaves(NODE_POOL, POOL_TOP);
  GenerateTree();
  ObtainPrefix((int)unique.length());
  PrintPrefix();
  ResolveOutput(unique);
  PrintOutput();
  return 0;
}
