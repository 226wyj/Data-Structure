#include <iostream>
using namespace std;

// 队列
class Queue {
private:
    int* queue;     // 指向队列的第一个元素
    int length;     // 队列中当前元素的个数
    int queueSize;  // 队列的最大容量
public:
    // 构造函数和析构函数
    Queue() {
        queue = nullptr;
        length = 0;     
        queueSize = 0;  
    }
    
    Queue(int size) {
        queue = new int[size]();
        length = 0;
        queueSize = size;
    }
    
    ~Queue() {
        delete[] queue;
    }

    // 私有成员属性的接口
    void setLength(int length) {
        this->length = length;
    }

    int getLength() {
        return this->length;
    }

    void setSize(int maxSize) {
        this->queueSize = maxSize;
    }

    int getSize() {
        return this->queueSize;
    }

    // 入队列
    void enQueue(int data) {
        if (this->getLength() < this->getSize()) {
            for (int i = getLength(); i > 0; i--) {
                queue[i] = queue[i-1];
            }
            queue[0] = data;
            setLength(getLength() + 1);
        }
        else {
            cout << "Queue Full! Can't hold more data!" << endl;
            exit(0);
        }
    }

    // 出队列
    int deQueue() {
        if (this->getLength()) {
            int result = queue[getLength()-1];
            setLength(getLength() - 1);
            return result;
        }
        else {
            cout << "Queue Empty! Please insert data first!" << endl;
            exit(0);
        }
    }

    // 展示队列中的内容
    void showQueue() {
        cout << "[ ";
        for (int i = 0; i < getLength(); i++)
            cout << queue[i] << " ";
        cout << "]" << endl;
    }
};

int main() {
    int maxSize = 10;
    Queue myQueue = Queue(10);
    
    // 入队列
    for (int i = 0; i < 5; i++) {
        myQueue.enQueue(i);
    }
    
    myQueue.showQueue();

    // 出队列
    cout << "Out queue: " << myQueue.deQueue() << endl;
    myQueue.showQueue();

    // 将5入队列
    myQueue.enQueue(5);
    myQueue.showQueue();

    return 0;
}