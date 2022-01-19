from linked_list import LinkedList

if __name__ == "__main__":
    linked_list = LinkedList()

    print("Insert from the head: 0~4")
    for i in range(0, 5):
        linked_list.add_node_at_head(i)
    linked_list.print_list()

    print("Insert from the tail: 5~9")
    for i in range(5, 10):
        linked_list.add_node_at_tail(i)
    linked_list.print_list()

    print("Length of the List: ", linked_list.length)

    print("Remove the node whose value is 0:")
    result = linked_list.remove_node(0)
    linked_list.print_list()

    print("Insert number 10 at position 0:")
    linked_list.insert_node(0, 10)
    linked_list.print_list()

    print("reverse the linked list:")
    linked_list.reverse()
    linked_list.print_list()