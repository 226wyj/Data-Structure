class Node:
    def __init__(self, value, left=None, right=None) -> None:
        self.value = value
        self.left = left
        self.right =right

class BinaryTree:
    def __init__(self, root=None) -> None:
        self.root = root
    
    # 添加结点
    def add(self, value):
        node = Node(value)
        if self.root is None:
            self.root = node
            return

        # 通过队列来找到待添加的结点位置
        queue = [self.root]
        curr_node = queue.pop(0)
        # 插入到左子树
        if curr_node.left is None:
            curr_node.left = node
            return
        # 将左孩子插入到队列中，下一次开始循环左结点
        else:
            queue.append(curr_node.left)
        
        if curr_node.right is None:
            curr_node.right = node
            return 
        else:
            queue.append(curr_node.right)
    
    # 层序遍历（广度优先遍历思想）
    def breadth_traverse(self):
        if self.root is None:
            return 

        # 通过维护一个队列来一层一层地进行扫描
        queue = [self.root]
        while queue:
            curr_node = queue.pop(0)
            print(curr_node.value)

            if curr_node.left is not None:
                queue.append(curr_node.left)
            if curr_node.right is not None:
                queue.append(curr_node.right)
    
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