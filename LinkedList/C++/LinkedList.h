#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node {
    int data;
    Node *next;
};

// 链表定义
class LinkedList {
private:
    // 头结点，指向链表中的第一个数据结点
    Node* head;

public:
    // 构造函数
    LinkedList();

    // 获取头结点
    Node* getHead();

    // 获取链表长度
    int getLength();

    // 在链表末尾追加数据（尾插法）
    void appendData(int data);

    // 删除链表中值为value的结点，成功返回1，否则返回0
    int deleteData(int data);

    // 在链表特定位置中插入数据，index从0开始，插入的数据作为链表中的第index个结点
    bool insertData(int index, int data);

    // 获取链表中某一位置的数据，index从0开始
    int getData(int index);

    // 反转链表
    Node* reverseList();

    // 清空链表
    void clearList();

    // 输出链表中的内容
    void showList();
};


#endif