from typing import List


class Node(object):
    def __init__(self) -> None:
        self.child = {}
        self.is_word = False


class Trie(object):
    def __init__(self) -> None:
        self.root = Node()
    
    def insert(self, word: str) -> None:
        curr = self.root
        for char in word:
            if not curr.child.get(char):
                curr.child[char] = Node()
            curr = curr.child[char]
        curr.is_word = True
    
    def search_prefix(self, prefix: str) -> List[str]:
        curr = self.root
        res = []
        path = []
        for char in prefix:
            if char not in curr.child:
                return []
            else:
                path.append(char)
                curr = curr.child[char]
        
        def backtracking(root: Node) -> None:
            if not root:
                return
            if root.is_word:
                res.append(''.join(path))
            for char, next in root.child.items():
                path.append(char)
                backtracking(next)
                path.pop()
            
        backtracking(curr)
        return res


if __name__ == '__main__':
    trie = Trie()
    products = ["mobile","mouse","moneypot","monitor","mousepad"]
    for p in products:
        trie.insert(p)
    res = trie.search_prefix('mo')
    print(res)
    