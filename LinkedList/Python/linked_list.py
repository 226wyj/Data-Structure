from multiprocessing import dummy
from typing import List


class Node:
    """ Definition of list node. """
    def __init__(self, val=0, next=None) -> None:
        self.val = val
        self.next = next


class LinkedList:
    """ Definition of linked list. """
    def __init__(self, head=None, tail=None, length=0) -> None:
        self.head = head
        self.tail = tail
        self.length = length
    
    def __repr__(self) -> str:
        return 'head={}, tail={}, length={}'.format(self.head.val, self.tail.val, self.length)

    def print_list(self) -> None:
        """ Prints all the node values of the linked list. """
        curr = self.head
        while curr:
            end_symbol = ' -> ' if curr.next else ''
            print(curr.val, end=end_symbol)
            curr = curr.next
    
    def get_values(self) -> List[int]:
        """ Gets all the node values of the linked list. """
        curr = self.head
        res = []
        while curr:
            res.append(curr.val)
            curr = curr.next
        return res

    def append_front(self, num: int) -> None:
        """ Appends a new node at the head of the linked list. """
        if not self.head:
            self.head = Node(num)
            self.tail = self.head
        else:
            new_node = Node(num, self.head)
            self.head = new_node
        self.length += 1
        
    def append_back(self, num: int) -> None:
        """ Appends a new node at the tail of the linked list. """
        if not self.head:
            self.head = Node(num)
            self.tail = self.head
        else:
            self.tail.next = Node(num)
            self.tail = self.tail.next
        self.length += 1

    def remove(self, num: int) -> int:
        """ Removes a node based on the target value. """
        dummy_head = Node(0, self.head)
        curr = self.head
        pre = dummy_head
        while curr:
            if curr.val == num:
                if curr == self.head:
                    self.head = curr.next
                if curr == self.tail:
                    self.tail = pre
                pre.next = curr.next
                self.length -= 1
                return 1
            else:
                pre = curr
                curr = curr.next
        return 0

    def insert(self, pos: int, num: int) -> None:
        """ Inserts a node on the target position. """
        if pos < 0 or pos > self.length + 1:
            print("The length of the list is {}, your pos is {}".format(self.length, pos))
            print("The range of the pos parameter should be within [0, length + 1].")
            return
        dummy_head = Node(0, self.head)
        curr = dummy_head
        while pos > 0:
            curr = curr.next
            pos -= 1
        new_node = Node(num, curr.next)
        curr.next = new_node
        if pos == 0:
            self.head = new_node
        if pos == self.length + 1:
            self.tail = new_node
        self.length += 1
        dummy_head.next = None
        del dummy_head

    def reverse(self) -> None:
        """ Reverses the linked list. """
        if not self.head or not self.head.next:
            return
        pre, curr = None, self.head
        self.tail = self.head
        while curr:
            tmp = curr.next
            curr.next = pre
            pre = curr
            curr = tmp
        self.head = pre