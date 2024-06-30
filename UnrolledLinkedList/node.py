class Node:
    def __init__(self, capacity=16) -> None:
        self.capacity = capacity    # 最大容量
        self.size = 0               # 当前容量
        self.elements = [None] * capacity
        self.next = None