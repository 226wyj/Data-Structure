from linked_list import LinkedList


if __name__ == "__main__":
    # Creates a linked list object.
    linked_list = LinkedList()

    # Test 1. Appends 0-4 to the front.
    print("\Append to the front: 0-4")
    for i in range(0, 5):
        linked_list.append_front(i)
    linked_list.print_list()
    print(linked_list)

    # Test 2. Appends 5-9 to the back. 
    print("\nAppend to the back: 5-9")
    for i in range(5, 10):
        linked_list.append_back(i)
    linked_list.print_list()
    print(linked_list)

    # Test 3. Inserts a number at the first postion.
    print("\nInsert number 10 at position 0:")
    linked_list.insert(0, 10)
    linked_list.print_list()
    print(linked_list)

    # Test 4. Inserts a number at the last position.
    print("\nInsert number 11 at position 11:")
    linked_list.insert(11, 11)
    linked_list.print_list()
    print(linked_list)

    # Test 5. Inserts a number in the middle.
    print("\nInsert number 12 at position 5:")
    linked_list.insert(5, 12)
    linked_list.print_list()
    print(linked_list)

    # Test 6. Reverse the linked list.
    print("\nreverse the linked list:")
    linked_list.reverse()
    linked_list.print_list()
    print(linked_list)

    # Test 7. Removes all the nodes of the linked list.
    print("\nRemove all the nodes whose values are from 0 to 12:")
    for i in range(0, 13):
        linked_list.remove(i)
        linked_list.print_list()
        print(linked_list)
    
    print()