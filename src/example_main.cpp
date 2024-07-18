#include <iostream>
#include "operator_trie.hpp"
int main()
{
  std::vector<char> alphabet;
  for(char ch = 'a'; ch <= 'z'; ch++)
  {
    alphabet.push_back(ch);
  }
  Trie trie(alphabet);
  trie.insert("abc");
  trie.insert("abb");
  std::cout<< trie.contains("abc") << "\n";
  std::cout<< trie.contains("abcd") << "\n";
  std::cout<< trie.contains("abb") << "\n"; 
}
