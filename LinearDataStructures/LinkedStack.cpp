#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

class LinkedStack {
private:
	Node* head;
	int length;
public:
	LinkedStack() {
		head = nullptr;
		length = 0;
	}

	~LinkedStack() {
		delete[] head;
	}

	Node* getHead() {
		return this->head;
	}

	int getLength() {
		return this->length;
	}

	void setLength(int length) {
		this->length = length;
	}

	// 入栈
	void push(int data) {
		Node* newNode = new(Node);
		newNode->data = data;
		newNode->next = nullptr;

		if (!head) {
			head = newNode;
		}
		else {
			newNode->next = head->next;
			head = newNode;
		}
		setLength(getLength() + 1);
	}	

	// 出栈
	int pop() {
		if (this->getLength() == 0) {
			cout << "Error! Stack Empty!" << endl;
			return -1;
		}
		else {
			int result = head->data;
			head = head->next;
			setLength(getLength() - 1);
			return result;
		}
	}

	// 展示栈中内容
	void showStack() {
		cout << "[ ";
		Node* currentPointer = this->head;
		while (currentPointer) {
			cout << currentPointer->data << " ";
			currentPointer = currentPointer->next;
		}
		cout << "]" << endl;
	}
};

int main() {
	LinkedStack myStack = LinkedStack();
	for (int i = 0; i < 5; i++)
		myStack.push(i);
	myStack.showStack();
	return 0;
}