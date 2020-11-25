//
// Created by wyj on 2020/11/25.
//

#ifndef HASHMAP_LINKEDLIST_H
#define HASHMAP_LINKEDLIST_H

// 链表结点
struct Node {
    int key;
    int value;
    Node* next;

    Node();
    Node(int k, int v);
};

// 链表
class LinkedList {
private:
    // 头结点
    Node *head;

public:
    LinkedList();
    ~LinkedList();

    Node * getHead();
    void setHead(Node* h);

    // 通过关键字k查找结点
    Node * searchNode(int k);

    // 向链表中插入新结点，若关键字已经存在则覆盖原有的值
    void insertNode(int k, int v);

    // 删除关键字为k的结点
    Node * deleteNode(int k);

    // 输出链表的内容
    void showList();
};


#endif //HASHMAP_LINKEDLIST_H
