from typing import List


class Node(object):
    """ Definition of list node. """
    def __init__(self, val=0, next=None) -> None:
        self.val = val
        self.next = next


class LinkedList(object):
    """ Definition of linked list. """
    def __init__(self, head=None, tail=None, length=0) -> None:
        self.head = head
        self.tail = tail
        self.length = length
    
    def __repr__(self) -> str:
        head_val = self.head.val if self.head else 'None'
        tail_val = self.tail.val if self.tail else 'None'
        return 'head={}, tail={}, length={}'.format(head_val, tail_val, self.length)

    @staticmethod
    def _del(node: Node) -> None:
        """ Releases the memory allocated to the node object. """
        node.next = None
        del node

    def print_list(self) -> None:
        """ Prints all the node values of the linked list. """
        curr = self.head
        while curr:
            end_symbol = ' -> ' if curr.next else '\n'
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
        if self.length == 0:
            print("You can not remove anything from an empty linked list.")
            return 0
        curr = self.head
        pre = None
        while curr:
            if curr.val == num:
                # updates the head and tail pointers if necessary.
                if curr == self.head:
                    self.head = curr.next
                if curr == self.tail:
                    self.tail = pre
                
                # removes the target node.
                if pre:
                    pre.next = curr.next
                    self._del(curr)
                self.length -= 1
                return 1
            else:
                pre = curr
                curr = curr.next
        return 0

    def insert(self, pos: int, num: int) -> None:
        """ Inserts a node on the target position, pos should be within [0, length]. """
        if pos < 0 or pos > self.length:
            print("The length of the list is {}, your pos is {}".format(self.length, pos))
            print("The range of the pos parameter should be within [0, length].")
            return
        # Uses a dummy_head node for assistance,
        # so that we do not need to care about the corner case.
        dummy_head = Node(0, self.head)
        
        # Finds the target position.
        curr = dummy_head
        for _ in range(pos, 0, -1):
            curr = curr.next
        
        # Inserts the new node.
        new_node = Node(num, curr.next)
        curr.next = new_node

        # Adjust the head and tail pointers if necessary.
        if pos == 0:
            self.head = new_node
        if pos == self.length:
            self.tail = new_node
        
        # Updates length and releases the dummy_head node object.
        self.length += 1
        self._del(dummy_head)

    def reverse(self) -> None:
        """ Reverses the linked list. """
        # Corner case: there is at most 1 node in the list.
        if not self.head or not self.head.next:
            return
        # Uses two pointers to reverse the list in-place.
        pre, curr = None, self.head
        self.tail = self.head
        while curr:
            tmp = curr.next
            curr.next = pre
            pre = curr
            curr = tmp
        self.head = pre