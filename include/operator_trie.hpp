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
  friend struct TrieNode;
  struct TrieNode
  {
    std::shared_ptr<int> ptrs[ALPHABET_SIZE];
    char symbol;
    bool finish;
    TrieNode(char symbol, bool finish);
    bool has_word();
    bool possible_next(char symbol);
    friend class Trie;
  };
  std::shared_ptr<TrieNode> root;
public:
  Trie(std::vector<char> alphabet);
  std::vector<string> split_string(string str);
  void add_operator(string op);
  bool contains(string op);
};
