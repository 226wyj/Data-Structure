class Node:
    def __init__(self, value, left=None, right=None) -> None:
        self.value = value
        self.left = left
        self.right = right
    
class BinarySearchTree:
    def __init__(self, root=None) -> None:
        self.root = root
    
    # 添加结点
    def add(self, root, value):  
        node = Node(value)
        if not self.root:
            self.root = node
            return
        
        if value < self.root.value:
            self.root.left = self.add(self.root.left, value)
        elif value > self.root.value:
            self.root.right = self.add(self.root.right, value)
        return self.root

    # 层序遍历
    def breadth_traverse(self):
        if not self.root:
            return
        queue = [self.root]
        while queue:
            curr = queue.pop(0)
            print(curr.value)
            if curr.left is not None:
                queue.append(curr.left)
            if curr.right is not None:
                queue.append(curr.right)

    # 前序遍历
    def pre_order_traverse(self):
        if not self.root:
            return
        print(self.root.value)
        self.pre_order_traverse(self.root.left)
        self.pre_order_traverse(self.root.right)

    # 中序遍历
    def in_order_traverse(self):
        if not self.root:
            return  
        self.in_order_traverse(self.root.left)
        print(self.root.value)
        self.in_order_traverse(self.root.right)
    
    # 后序遍历
    def post_order_traverse(self):
        if not self.root:
            return
        self.post_order_traverse(self.root.left)
        self.post_order_traverse(self.root.right)
        print(self.root.value)

if __name__ == "__main__":
    binary_tree = BinarySearchTree()
    nums = [50, 30, 10, 0, 20, 40, 70, 90, 100, 60, 80]
    for i in nums:
        binary_tree.add(i)
    binary_tree.in_order_traverse()