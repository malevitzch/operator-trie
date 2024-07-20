#include <iostream>
#include "operator_trie.hpp"
int main()
{
  std::vector<string> operators = {"+", "-", "-=", "++", "*", "*=", "/", "/=", "+=", ">", "!", "!="};
  Trie trie(operators);
  string x = "+=++-*=*-!";
  
  for(auto cur : trie.split_string(x))
  {
    std::cout<<cur<< "\n";
  }
  //TODO: run a large test, comparing trie to std::set<string> to check if we missed anything
}
