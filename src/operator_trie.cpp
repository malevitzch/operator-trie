#include "operator_trie.hpp"
#include <algorithm>

int Trie::get_index(char target)
{
  int l = 0;
  int r = alphabet.size() - 1;
  while(l <= r)
  {
    int mid = (l + r) / 2;
    if(alphabet[mid] < target)
    {
      l = mid + 1;
    }
    else if(alphabet[mid] > target)
    {
      r = mid - 1;
    }
    else
    {
      return mid;
    }
  }
  return -1;
}

Trie::TrieNode::TrieNode(char symbol, bool finish, int alphabet_size) : symbol(symbol), finish(finish), ptrs(alphabet_size, nullptr) {}
bool Trie::TrieNode::possible_next(int index)
{
  return ptrs[index] != nullptr;
}
Trie::Trie(std::vector<char> alphabet) : alphabet(alphabet), root(std::make_shared<TrieNode>('\0', false, alphabet.size()))
{
  std::sort(alphabet.begin(), alphabet.end());
}
void Trie::insert(string word)
{
  std::shared_ptr<TrieNode> cur = root;

  for(char ch : word)
  {
    int index = get_index(ch);
    if(!cur->possible_next(index))
    { 
      cur->ptrs[index] = std::make_shared<TrieNode>(ch, false, alphabet.size());
    }
    cur = cur->ptrs[index];
  }
  cur->finish = true;
}
bool Trie::contains(string word)
{
  std::shared_ptr<TrieNode> cur = root;
  for(char ch : word)
  {
    int index = get_index(ch);
    if(!cur->possible_next(index))
    {
      return false;
    }
    cur = cur->ptrs[index];
  }
  return cur->finish;
}
