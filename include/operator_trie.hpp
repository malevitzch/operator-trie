#include <string>
#include <vector>
using std::string;
class OperatorTrie
{  
private:
  friend class TreeNode;
  class TrieNode
  {
    
  };
public:
  std::vector<string> split_string(string str);
  void add_operator(string op);
  bool contains(string op);
};
