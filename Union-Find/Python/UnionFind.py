class UnionFind(object):
    def __init__(self, count) -> None:
        self.count = count
        self.parent = [0] * count

        for i in range(count):
            self.parent[i] = i
    
    def _find(self, x):
        while self.parent[x] != x:
            # 压缩路径，将树的高度压缩至不超过3，从而使得 _find 的时间复杂度为 O(1)
            self.parent[x] = self.parent[self.parent[x]]
            x = self.parent[x]
        return x

    def union(self, p, q):
        root_p, root_q = self._find(p), self._find(q)
        if root_p == root_q:
            return
        self.parent[root_p] = root_q
        # 两个连通分量合为一个连通分量
        self.count -= 1
    
    def is_connected(self, p, q):
        return self._find(p) == self._find(q)
