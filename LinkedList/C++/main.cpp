//
// Created by wyj on 2021/10/8.
//
#include <iostream>
#include "LinkedList.h"

using std::cout;
using std::endl;

int main() {
    LinkedList myList = LinkedList();
    for (int i = 0; i < 5; i++) {
        myList.appendData(i);
    }
    cout << "LinkedList:" << endl;
    myList.showList();
    cout << "Length of the LinkedList:  " << myList.getLength() << endl;
    myList.deleteData(0);
    cout << "Delete Data 0:" << endl;
    myList.showList();
    cout << "Length of the LinkedList:  " << myList.getLength() << endl;
    cout << "Insert data 100 at index 0:" << endl;
    myList.insertData(0, 100);
    myList.showList();
    cout << "0th Element:  " << myList.getData(0) << endl;
    cout << "1st Element:  " << myList.getData(1) << endl;

    cout << "Reverse the LinkedList:" << endl;
    Node* reversedList = myList.reverseList();
    Node* head = reversedList;
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
    myList.clearList();
    return 0;
}