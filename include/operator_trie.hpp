#include <string>
#include <vector>
#include <memory>
using std::string;
#define ALPHABET_SIZE 26

class OperatorTrie
{ 
private:
  friend class TrieNode;
  class TrieNode
  {
  private:
    std::shared_ptr<int> ptrs[ALPHABET_SIZE];
    bool finish;
  public:
    friend class OperatorTrie;
  };
  std::shared_ptr<TrieNode> root;
public:
  std::vector<string> split_string(string str);
  void add_operator(string op);
  bool contains(string op);
};
