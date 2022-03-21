#include "Trie.h"


Trie::Trie() {
    root = new(Node);
}

void Trie::insert(string word) {
    Node* curr = root;
    for (auto c : word) {
        if (curr->child.find(c) == curr->child.end()) {
            curr->child.insert(pair<char, Node*> (c, new(Node)));
        }
        curr = curr->child.find(c);
    }
    curr->isWord = true;
}

