#include "LinkedQueue.h"

int main() {
    LinkedQueue myQueue = LinkedQueue();

    // 入队列
    for (int i = 0; i < 5; i++) {
        myQueue.enQueue(i);
    }
    cout << "Enque: 0~4" << endl;
    myQueue.showQueue();

    // 出队列
    cout << "Dequeue: " << myQueue.deQueue() << endl;
    myQueue.showQueue();

    // 将5入队列
    cout << "Insert 5 into the queue:" << endl;
    myQueue.enQueue(5);
    myQueue.showQueue();

    // 队列长度
    cout << "The length of the queue: " << myQueue.getLength() << endl;

    return 0;
}