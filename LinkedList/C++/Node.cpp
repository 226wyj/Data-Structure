#include <iostream>
#include "Node.h"

Node::Node(): data(0), next(nullptr) {}

Node::Node(int d): data(d), next(nullptr) {}

Node::Node(int d, Node* n): data(d), next(n) {}

int Node::getData() {
    return this->data;
}

void Node::setData(int d) {
    this->data = d;
}

Node* Node::getNext() {
    return this->next;
}

void Node::setNext(Node* n) {
    this->next = n;
}
