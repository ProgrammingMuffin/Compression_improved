#include<iostream>
#include "manipulate.h"

std::string GetUnique(std::string str)
{
  int i, j;
  std::string temp;
  temp.push_back(str[0]);
  for(i=1;i<(int)str.length();i++)
  {
    //std::cout<<"Loop 1"<<std::endl;
    for(j=0;j<(int)temp.length();j++)
    {
      //std::cout<<"Loop 2"<<std::endl;
      if(temp[j] == str[i])
      {
        //std::cout<<"break encountered!"<<std::endl;
        break;
      }
    }
    if(j == (int)temp.length())
      temp.push_back(str[i]);
  }
  return temp;
}


void GetCount(std::string in_str, int count[], std::string temp)
{
     int i, j, c=0;
     for(i=0;i<(int)temp.length();i++)
     {
       for(j=0;j<(int)in_str.length();j++)
       {
         if(temp[i] == in_str[j])
         {
           c++;
         }
       }
       count[i] = c;
       c = 0;
     }
}
