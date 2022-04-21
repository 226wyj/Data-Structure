#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

// 链表定义
class LinkedList {
private:
    Node* head;
    Node* tail;
    int length;

    void deleteNode(Node* node) {
        node->setNext(nullptr);
        delete node;
    }

public:
    // Constructor.
    LinkedList();

    // Destructor.
    ~LinkedList();

    // Gets head node of the linked list.
    Node* getHead();

    // Gets tail node of the linked list.
    Node* getTail();

    // Gets length of the linked list.
    int getLength();

    // Appends data at the beginning of the linked list.
    void appendFront(int data);

    // Appends data at the end of the linked list.
    void appendBack(int data);

    // Removes target node based on the given data value.
    int remove(int data);

    // 在链表特定位置中插入数据，index从0开始，插入的数据作为链表中的第index个结点
    void insert(int pos, int data);

    // 获取链表中某一位置的数据，index从0开始
    Node* getNode(int index);

    // Reverses the linked list.
    void reverse();

    // 清空链表
    void clear();

    // 输出链表中的内容
    void printList();
};


#endif