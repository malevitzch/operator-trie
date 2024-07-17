#include <string>
#include <vector>
#include <memory>
using std::string;
#define ALPHABET_SIZE 26

class Trie
{ 
private:
  std::vector<char> alphabet;
  int get_index(char target);
  friend class TrieNode;
  class TrieNode
  {
  private:
    std::shared_ptr<int> ptrs[ALPHABET_SIZE];
    bool finish;
    char symbol;
  public:
    friend class Trie;
  };
  std::shared_ptr<TrieNode> root;
public:
  Trie(std::vector<char> alphabet);
  std::vector<string> split_string(string str);
  void add_operator(string op);
  bool contains(string op);
};
