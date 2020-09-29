#include <iostream>
using namespace std;

// 数据节点定义
struct Node {
    int data;
    Node* next;
};

// 链表定义
class LinkedList {
private:
    // 头节点
    Node* head;

public:
    LinkedList() {
        head = nullptr;
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

    // 在链表末尾追加数据（尾插法）
    void appendData(int data) {
        // 生成新的节点
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

    // 删除链表中值为value的节点，成功返回1，否则返回0
    int deleteData(int data) {
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

    // 在链表特定位置中插入数据，index从0开始，插入的数据作为链表中的第index个节点
    bool insertData(int index, int data) {
        if (index < 0 || index > this->getLength()) {
            cout << "Index Out of Range Error!" << endl;
            return false;
        }
        else {
            // 生成新的数据节点
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
    cout << "链表:" << endl;
    myList.showList();
    cout << "链表长度:  " << myList.getLength() << endl;
    myList.deleteData(0);
    cout << "删除元素0之后的链表:" << endl;
    myList.showList();
    cout << "链表长度:  " << myList.getLength() << endl;

    myList.insertData(0, 100);
    myList.showList();
    return 0;
}