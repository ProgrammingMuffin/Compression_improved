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
  InitLeaves(unique, count);
  InjectPool();
  PrintLeaves(LEAF, POOL_TOP);
  return 0;
}
//where r other files????
//it's there in my hard drive ;)
// but yeah. I wanna get rid of that .git crap
//open the terminal done

//nvm
//you can see the terminal logs? ohh.. maybe I forgot the --global crap let me see.
// nope.. doesnt work


//u here??
