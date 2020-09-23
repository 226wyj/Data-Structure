#include <iostream>
using namespace std;

// 数据节点定义
struct Node {
    int data;
    Node* next;
};

// 头节点定义
struct Head {
    Node* next;
};

// 链表类
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head->next = nullptr;
    }

    Node* getHead() {
        return this->head;
    }

    // 获取链表长度
    int getLength() {
        Node* currentPointer = this->head;
        int length = 0;
        while (currentPointer != nullptr) {
            currentPointer = currentPointer->next;
            length++;
        }
        return length;
    }

    // 在链表末尾追加数据
    void appendData(int data) {
        // 生成新的节点
        Node* newNode = new(Node);
        newNode->data = data;
        newNode->next = nullptr;

        if (head->next == nullptr) {
            head->next = newNode;
        }
        else {
            Node* currentPointer = head;
            while (currentPointer->next != nullptr) {
                currentPointer = currentPointer->next;
            }
            currentPointer->next = newNode;
        }
    }

    // 在链表特定位置中插入数据，index从0开始
    bool insertData(int index, int data) {
        if (index < 0 || index > this->getLength()) {
            cout << "Index Out of Range Error!" << endl;
            return false;
        }
        else {
            Node* newNode = new(Node);
            newNode->data = data;
            newNode->next = nullptr;
            Node* currentPointer = this->head;
            for (int i = 0; i < index; i++) {
                currentPointer = currentPointer->next;
            }
            auto temp = currentPointer->next;
            currentPointer->next = newNode;
            newNode->next = temp;
        }
        return true;
    }

    // 删除链表中某一位置的数据
    bool deleteData(int index, int data) {

    }

    // 获取链表中某一位置的数据，index从0开始
    int getData(int index) {
        if (index < 0 || index >= this->getLength()) {
            cout << "Index Out of Range Error!";
            return -1;
        }
        else {
            Node* currentPointer = this->head;
            for (int i = 0; i <= index; i++) {
                currentPointer = currentPointer->next;
            }
            return currentPointer->data;
        }
    }

    // 清空链表
    void clearList() {
        this->head = nullptr;
    }

    // 输出链表中的内容
    void showList() {
        cout << "[ ";
        Node* pre = head;
        while (pre != nullptr) {
            cout << pre->data << ' ';
            pre = pre->next;
        }
        cout << "]" << endl;
    }
};

int main() {
    LinkedList myList = LinkedList();
    for (int i = 0; i < 5; i++) {
        myList.appendData(i);
    }
    myList.showList();
    cout << myList.getLength() << endl;
    // myList.insertData(-1, 6);
    // myList.showList();
    cout << myList.getData(0);
    return 0;
}