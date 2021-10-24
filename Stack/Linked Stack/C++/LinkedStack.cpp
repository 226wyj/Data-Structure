#include <iostream>

#include "LinkedStack.h"

using namespace std;


LinkedStack::LinkedStack() {
	head = nullptr;
	length = 0;
}

LinkedStack::~LinkedStack() {
	if (head->next != nullptr) {
		Node* curr = head->next;
		while (curr != nullptr) {
			Node* tmp = curr;
			curr = curr->next;
			delete tmp;
		}
	}
	delete head;
}

Node* LinkedStack::getHead() {
	return this->head;
}

int LinkedStack::getLength() {
	return this->length;
}


// 入栈
void LinkedStack::push(int data) {
	Node* newNode = new(Node);
	newNode->data = data;
	newNode->next = nullptr;

	if (!head) {
		head = newNode;
	}
	else {
		newNode->next = head;
		head = newNode;
	}
	this->length++;
}

// 出栈
int LinkedStack::pop() {
	if (this->getLength() == 0) {
		cout << "Error! Stack Empty!" << endl;
		return -1;
	}
	else {
		int result = head->data;
		Node* tmp = head;
		head = head->next;
		this->length--;
		delete tmp;
		return result;
	}
}

// 展示栈中内容
void LinkedStack::showStack() {
	cout << " head [ ";
	Node* currentPointer = this->head;
	while (currentPointer) {
		cout << currentPointer->data << " ";
		currentPointer = currentPointer->next;
	}
	cout << "] tail" << endl;
}
