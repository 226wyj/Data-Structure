#include <iostream>
#include "LinkedList.h"

using std::cout;
using std::endl;

LinkedList::LinkedList() {
    head = nullptr;
}

Node* LinkedList::getHead() {
    return this->head;
}

// 获取链表长度
int LinkedList::getLength() {
    Node* currentPointer = this->head;
    int length = 0;
    while (currentPointer != nullptr) {
        currentPointer = currentPointer->next;
        length++;
    }
    return length;
}

// 在链表末尾追加数据（尾插法）
void LinkedList::appendData(int data) {
    // 生成新的结点
    Node* newNode = new(Node);
    newNode->data = data;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
    }
    else {
        Node* currentPointer = head;
        while (currentPointer->next != nullptr) {
            currentPointer = currentPointer->next;
        }
        currentPointer->next = newNode;
    }
}

// 删除链表中值为value的结点，成功返回1，否则返回0
int LinkedList::deleteData(int data) {
    Node* currentPointer = this->head;
    Node* prePointer = nullptr;
    int flag = 0;
    while (currentPointer != nullptr) {
        // 找到data，将其删除
        if (currentPointer->data == data) {
            if (currentPointer == this->head)
                head = head->next;
            else {
                if (prePointer == head)
                    prePointer = currentPointer->next;
                else
                    prePointer->next = currentPointer->next;
            }
            flag = 1;
            break;
        }
        // 未找到data，则继续遍历
        else {
            prePointer = currentPointer;
            currentPointer = currentPointer->next;
        }
    }
    return flag;
}

// 在链表特定位置中插入数据，index从0开始，插入的数据作为链表中的第index个结点
bool LinkedList::insertData(int index, int data) {
    if (index < 0 || index > this->getLength()) {
        cout << "Index Out of Range Error!" << endl;
        return false;
    }
    else {
        // 生成新的数据结点
        Node* newNode = new(Node);
        newNode->data = data;
        newNode->next = nullptr;
        // 找到待插入的位置
        if (index == 0) {
            Node* temp = head;
            head = newNode;
            newNode->next = temp;
        }
        else {
            Node* currentPointer = this->head;
            for (int i = 0; i < index - 1; i++) {
                currentPointer = currentPointer->next;
            }
            Node* temp = currentPointer->next;
            currentPointer->next = newNode;
            newNode->next = temp;
        }
    }
    return true;
}


// 获取链表中某一位置的数据，index从0开始
int LinkedList::getData(int index) {
    int result = 0;
    if (index < 0 || index > this->getLength() - 1) {
        cout << "Index Out of Range Error!";
        return -1;
    }
    else {
        if (index == 0)
            result = head->data;
        else {
            Node* currentPointer = this->head;
            for (int i = 0; i < index; i++) {
                currentPointer = currentPointer->next;
            }
            result = currentPointer->data;
        }
    }
    return result;
}

// 反转链表
Node* LinkedList::reverseList() {
    Node* newHead = nullptr;
    for (int i = 0; i < this->getLength(); i++) {
        // 取原始链表中的数据，构造新结点
        Node* newNode = new(Node);
        newNode->data = this->getData(i);
        newNode->next = nullptr;

        // 头插法构造新链表，从而实现原始列表的反转
        if (!newHead) {
            newHead = newNode;
        }
        else {
            newNode->next = newHead;
            newHead = newNode;
        }
    }
    return newHead;
}

// 清空链表
void LinkedList::clearList() {
    Node* current = this->head;
    while (current) {
        auto temp = current;
        current = current->next;
        delete temp;
    }
    this->head = nullptr;
}

// 输出链表中的内容
void LinkedList::showList() {
    cout << "[ ";
    Node* pre = head;
    while (pre != nullptr) {
        cout << pre->data << ' ';
        pre = pre->next;
    }
    cout << "]" << endl;
}

