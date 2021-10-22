#include <climits>
#include <iostream>

using std::cout;
using std::endl; 

// node of the queue
struct Node {
    int data;
    Node* next;

    Node() {
        data = INT_MAX;
        next = nullptr;
    }
};

// queue based on linked list
class LinkedQueue {
private:
    Node* head;
    int length = 0;
public:
    LinkedQueue();

    // 私有成员属性的接口
    Node* getHead();

    int getLength();

    // 入队列（先进先出，即头插法建立链表）
    void enQueue(int data);

    // 出队列（依次从后向前输出链表中的值）
    int deQueue();

    // 展示队列中的内容
    void showQueue();
};