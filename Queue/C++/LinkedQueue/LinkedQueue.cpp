#include "LinkedQueue.h"


LinkedQueue::LinkedQueue() {
    head = nullptr;
    length = 0;
}

// 私有成员属性的接口
Node* LinkedQueue::getHead() {
    return this->head;
}

int LinkedQueue::getLength() {
    return this->length;
}

// 入队列（先进先出，即头插法建立链表）
void LinkedQueue::enQueue(int data) {
    Node* newNode = new(Node);
    newNode->data = data;

    if (head == nullptr)
        head = newNode;
    else {
        newNode->next = head;
        head = newNode;
    }
    this->length += 1;
}

// 出队列（依次从后向前输出链表中的值）
int LinkedQueue::deQueue() {
    if (getLength() == 0) {
        cout << "Error! Empty Queue!" << endl;
        exit(0);
    } else {
        Node* currentPointer = getHead();
        Node* parent = nullptr;
        while (currentPointer->next) {
            parent = currentPointer;
            currentPointer = currentPointer->next;
        }
        int result = currentPointer->data;
        parent->next = nullptr;
        delete currentPointer;
        this->length -= 1;
        return result; 
    }
}

// 展示队列中的内容
void LinkedQueue::showQueue() {
    cout << "[ ";
    Node* current = getHead();
    while(current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "]" << endl;
}


