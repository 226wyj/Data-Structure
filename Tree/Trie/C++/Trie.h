#include <map>
#include <vector>
#include <string>

using namespace std;

struct Node {
    map<char, Node*> child;
    bool isWord = false;
};

class Trie {
private:
    Node* root;

public:
    Trie();

    ~Trie();

    void insert(string word);

    vector<string> searchPrefix(string prefix);
};
