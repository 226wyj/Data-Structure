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
    def add_node(self, value):  

        def insert(root, value):
            node = Node(value)
            if not root:
                root = node
            elif root.value < value:
                root.right = insert(root.right, value)
            elif root.value > value:
                root.left = insert(root.left, value)
            else:
                raise ValueError("Value {} has already existed.".format(value))
            return root
        
        self.root = insert(self.root, value)


    # 层序遍历
    def breadth_traverse(self) -> List[int]:
        if not self.root:
            return
        queue = deque()
        queue.append(self.root)
        res = []
        while queue:
            curr: Node = queue.popleft()
            res.append(curr.value)
            if curr.left:
                queue.append(curr.left)
            if curr.right:
                queue.append(curr.right)
        return res

    # 前序遍历
    def pre_order_traverse(self) -> List[int]:
        res = []

        def traverse(root: Node):
            if not root:
                return
            res.append(root.value)
            traverse(root.left)
            traverse(root.right)
        
        traverse(self.root)
        return res

    # 中序遍历
    def in_order_traverse(self) -> List[int]:
        res = []

        def traverse(root: Node):
            if not root:
                return
            traverse(root.left)
            res.append(root.value)
            traverse(root.right)
        
        traverse(self.root)
        return res
    
    # 后序遍历
    def post_order_traverse(self) -> List[int]:
        res = []
        
        def traverse(root: Node):
            if not root:
                return
            traverse(root.left)
            traverse(root.right)
            res.append(root.value)
        
        traverse(self.root)
        return res


if __name__ == "__main__":
    binary_tree = BinarySearchTree()
    nums = [50, 30, 10, 0, 20, 40, 70, 90, 100, 60, 80]
    for i in nums:
        binary_tree.add_node(i)
    print(binary_tree.in_order_traverse())