from typing import List
from collections import deque


class Node:
    def __init__(self, value=0, left=None, right=None) -> None:
        self.value = value
        self.left = left
        self.right = right
    
class BinarySearchTree:
    def __init__(self) -> None:
        self.root = None
    
    # 添加结点
    def insert(self, root, value):  
        # TODO: to be done
        node = Node(value)
        if not self.root:
            self.root = node
        
        if value < root.value:
            root.left 
            return self.root.left.add(value)
        elif value > self.root.value:
            return self.root.right.add(value)
        else:
            raise ValueError("Value {} has already existed.".format(value))

    # 层序遍历
    def breadth_traverse(self) -> List[int]:
        if not self.root:
            return
        queue = deque()
        queue.append(self.root)
        res = []
        while queue:
            curr = queue.popleft()
            res.append(curr.value)
            if curr.left:
                queue.append(curr.left)
            if curr.right:
                queue.append(curr.right)
        return res

    # 前序遍历
    def pre_order_traverse(self) -> List[int]:
        res = []

        def traverse(root):
            if not self.root:
                return
            res.append(root.value)
            self.pre_order_traverse(self.root.left)
            self.pre_order_traverse(self.root.right)
        
        traverse(self.root)
        return res

    # 中序遍历
    def in_order_traverse(self) -> List[int]:
        res = []

        def traverse(root):
            if not self.root:
                return
            self.in_order_traverse(self.root.left)
            res.append(root.value)
            self.in_order_traverse(self.root.right)
        
        traverse(self.root)
        return res
    
    # 后序遍历
    def post_order_traverse(self) -> List[int]:
        res = []
        
        def traverse(root):
            if not self.root:
                return
            self.post_order_traverse(self.root.left)
            self.post_order_traverse(self.root.right)
            res.append(root.value)
        
        traverse(self.root)
        return res


if __name__ == "__main__":
    binary_tree = BinarySearchTree()
    nums = [50, 30, 10, 0, 20, 40, 70, 90, 100, 60, 80]
    for i in nums:
        binary_tree.add(i)
    binary_tree.in_order_traverse()