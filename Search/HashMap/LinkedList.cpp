//
// Created by wyj on 2020/11/25.
//
#include "LinkedList.h"

Node::Node() {
    key = 0;
    value = 0;
    next = nullptr;
}

Node::Node(int k, int v) {
    key = k;
    value = v;
    next = nullptr;
}

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {
    Node *current = getHead();
    while (current != nullptr) {
        Node *tmp = current;
        current = current->next;
        delete tmp;
    }
    delete getHead();
}

Node * LinkedList::getHead() {
    return head;
}

void LinkedList::setHead(Node *h) {
    head = h;
}

Node * LinkedList::searchNode(int k) {
    Node *current = getHead();
    while (current != nullptr) {
        if (current->key == k) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void LinkedList::insertNode(int k, int v) {
    Node *current = getHead();
    Node *tmp = searchNode(k);
    if (tmp != nullptr) {
        tmp->value = v;
    }
    else {
        Node *newNode = new Node(k, v);
        newNode->next = current->next;
        current->next = newNode;
    }
}

Node * LinkedList::deleteNode(int k) {
    Node *current = getHead();
    Node *tmp = searchNode(k);
    if (tmp == nullptr) {
        return nullptr;
    }
    else {
        
    }
}
