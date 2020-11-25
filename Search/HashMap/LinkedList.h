//
// Created by wyj on 2020/11/25.
//

#ifndef HASHMAP_LINKEDLIST_H
#define HASHMAP_LINKEDLIST_H

struct Node {
    int key;
    int value;
    Node* next;

    Node();
    Node(int k, int v);
};

class LinkedList {
private:
    Node *head;

public:
    LinkedList();
    ~LinkedList();

    Node * getHead();
    void setHead(Node* h);
    Node * searchNode(int k);
    void insertNode(int k, int v);
    Node * deleteNode(int k);
};


#endif //HASHMAP_LINKEDLIST_H
