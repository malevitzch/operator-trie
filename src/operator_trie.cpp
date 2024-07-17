#include "operator_trie.hpp"

int Trie::get_index(char target)
{
  int l = 0;
  int r = alphabet.size() - 1;
  while(l < r)
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

