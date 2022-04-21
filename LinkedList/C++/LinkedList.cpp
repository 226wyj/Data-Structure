#include <iostream>
#include "LinkedList.h"


using std::cout;
using std::endl;


LinkedList::LinkedList(): head(nullptr), tail(nullptr), length(0) {}


LinkedList::~LinkedList() {
    Node* curr = head;
    while (curr) {
        Node* tmp = curr;
        curr = curr->getNext();
        tmp->setNext(nullptr);
        delete tmp;
    }
    delete this;
}


Node* LinkedList::getHead() {
    return this->head;
}


Node* LinkedList::getTail() {
    return this->tail;
}


int LinkedList::getLength() {
    return this->length;
}


void LinkedList::appendFront(int data) {
    if (!head) {
        head = new Node(data);
        tail = head;
    } else {
        Node* newNode = new Node(data, head);
        head = newNode;
    }
    length++;
}


void LinkedList::appendBack(int data) {
    if (!head) {
        head = new Node(data);
        tail = head;
    } else {
        tail->setNext(new Node(data));
        tail = tail->getNext();
    }
    length++;
}


int LinkedList::remove(int data) {
    if (length == 0) {
        cout << "You can not remove anything from an empty linked list." << endl;
        return 0;
    }
    Node* curr = this->head;
    Node* pre = nullptr;
    while (curr) {
        if (curr->getData() == data) {
            // updates the head and tail pointers if necessary.
            if (curr == this->head) {
                head = curr->getNext();                
            }
            if (curr == this->tail) {
                tail = pre;
            }

            // removes the target node.
            if (pre) {
                pre->setNext(curr->getNext());
                this->deleteNode(curr);
            }
            return 1;
        } else {
            pre = curr;
            curr = curr->getNext();
        }
    }
    return 0;
}


void LinkedList::insert(int pos, int data) {
    if (pos < 0 || pos > getLength()) {
        cout << "The length of the list is " << length << ", your pos is " << pos << endl;
        cout << "The range of the pos parameter should be within [0, length]." << endl;
        return;
    }
    // Uses a dummy_head node for assistance,
    // so that we do not need to care about the corner case.
    Node* dummy_head = new Node(0, head);

    // Finds the target position.
    Node* curr = dummy_head;
    for (int i = pos; i > 0; i--) {
        curr = curr->getNext();
    }

    // Inserts the new node.
    Node* newNode = new Node(data, curr->getNext());
    curr->setNext(newNode);

    // Adjust the head and tail pointers if necessary.
    if (pos == 0) {
        head = newNode;
    }
    if (pos == getLength()) {
        tail = newNode;
    }

    length++;
    deleteNode(dummy_head);
}


Node* LinkedList::getNode(int index) {
    if (index < 0 || index >= getLength()) {
        cout << "The length of the list is " << length << ", your index is " << index << endl;
        cout << "The range of the pos parameter should be within [0, length - 1]" << endl;
        return nullptr;
    }
    Node* curr = head;
    for (int i = 0; i < index; i++) {
        curr = curr->getNext();
    }
    return curr;
}


void LinkedList::reverse() {
    if (!head || !head->getNext()) {
        return;
    }

    Node* pre = nullptr;
    Node* curr = head;
    tail = head;
    while (curr) {
        Node* tmp = curr->getNext();
        curr->setNext(pre);
        pre = curr;
        curr = tmp;
    }
    head = pre;
}


void LinkedList::clear() {
    Node* curr = head;
    while (curr) {
        Node* tmp = curr;
        curr = curr->getNext();
        tmp->setNext(nullptr);
        delete tmp;
    }
    head = nullptr;
    tail = nullptr;
    length = 0;
}


void LinkedList::printList() {
    Node* curr = head;
    while (curr->getNext()) {
        cout << curr->getData() << " -> ";
    }
    cout << curr->getData() << endl;
}

