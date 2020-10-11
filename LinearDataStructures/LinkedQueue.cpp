#include <iostream>
#include <climits>
using namespace std;

// 结点定义
struct Node {
    int data;
    Node* next;

    Node() {
        data = INT_MAX;
        next = nullptr;
    }
};

class LinkedQueue {
private:
    Node* head;
    int length = 0;
public:
    LinkedQueue() {
        head = nullptr;
        length = 0;
    }

    // 私有成员属性的接口
    Node* getHead() {
        return this->head;
    }

    void setLength(int length) {
        this->length = length;
    }

    int getLength() {
        return this->length;
    }

    // 入队列
    void inQueue(int data) {
        Node* newNode = new(Node);
        newNode->data = data;

        if (head == nullptr)
            head = newNode;
        else {
            newNode->next = head->next;
            head->next = newNode;
        }
        setLength(getLength() + 1);
    }

    // 出队列
    int outQueue() {
        if (getLength() == 0) {
            cout << "Error! Empty Queue!" << endl;
            exit(0);
        }
        else {
            Node* currentPointer = getHead();
            while (currentPointer) {
                currentPointer = currentPointer->next;
            }
            int result = currentPointer->data;
            setLength(getLength() - 1);
            return result; 
        }
    }

    // 展示队列中的内容
    void showQueue() {
        cout << "[ ";
        Node* current = getHead();
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "]" << endl;
    }
};

int main() {
    LinkedQueue myQueue = LinkedQueue();

    // 入队列
    for (int i = 0; i < 5; i++) {
        myQueue.inQueue(i);
    }
    
    myQueue.showQueue();

    // 出队列
    cout << "Out queue: " << myQueue.outQueue() << endl;
    myQueue.showQueue();

    // 将5入队列
    myQueue.inQueue(5);
    myQueue.showQueue();

    return 0;
}