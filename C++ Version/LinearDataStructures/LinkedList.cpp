#include <iostream>
#include <cstdio>
using namespace std;

struct Node {
    int data;
    Node* next;
};


class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void appendData(int data) {
        Node* newNode = new(Node);
        newNode->data = data;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* pre = head;
            while (pre->next != nullptr) {
                pre = pre->next;
            }
            pre->next = newNode;
        }
    }

    void showList() {
        cout << "[ ";
        Node* pre = head;
        while (pre != nullptr) {
            cout << pre->data << ' ';
            pre = pre->next;
        }
        cout << " ]" << endl;
    }
};

int main() {
    LinkedList myList = LinkedList();
    myList.appendData(1);
    myList.appendData(2);
    myList.appendData(3);
    myList.showList();
    return 0;
}