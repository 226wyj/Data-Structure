#include <iostream>
using namespace std;

// 栈
class Stack {
private:
	int* stack;		// 指向栈
	int stackSize;	// 栈的最大容量
	int length;		// 栈内元素的个数
public:
	Stack() {
		stack = nullptr;
		stackSize = 0;
		length = 0;
	}

	Stack(int size) {
		stackSize = size;
		stack = new int[size]();	
		length = 0;
	}

	~Stack() {
		delete [] stack;
	}

	// 获取栈的最大容量
	int getStackSize() {
		return stackSize;
	}

	// 设置栈的最大容量
	void setStackSize(int size) {
		this->stackSize = size;
	}

	// 获取栈内元素个数
	int getLength() {
		return length;
	}

	// 设置栈内的元素个数
	void setLength(int length) {
		this->length = length;
	}

	// 入栈
	int push(int data) {
		if (this->getLength() < this->getStackSize()) {
			for (int i = this->getStackSize() - 1; i > 0; i--) {
				stack[i] = stack[i - 1];
			}
			stack[0] = data;
			setLength(getLength() + 1);	// 插入新元素后同步更新栈内元素的个数
			return 1;
		}
		else {
			cout << "Error! Stack Full!" << endl;
			return -1;
		}
	}

	// 出栈
	int pop() {
		if (this->getLength() == 0) {
			cout << "Error! Stack Empty!" << endl;
			return -1;
		}
		else {
			int result = stack[0];
			for (int i = 0; i < this->getStackSize() - 1; i++) {
				stack[i] = stack[i + 1];
			}
			setLength(getLength() - 1);
			return result;
		}
	}

	// 展示栈中的内容
	void showStack() {
		cout << "[ ";
		for (int i = 0; i < this->getLength(); i++) {
			cout << this->stack[i] << " ";
		}
		cout << "]" << endl;
	}
};

int main() {
	int maxSize = 10;
	Stack myStack = Stack(maxSize);
	for (int i = 0; i < 5; i++)
		myStack.push(i);
	myStack.showStack();
	cout << "Stack Max Size: " << myStack.getStackSize() << endl;
	cout << "Stack Length: " << myStack.getLength() << endl;
	cout << "pop: " << myStack.pop() << endl;
	myStack.showStack();
	cout << "Stack Length: " << myStack.getLength() << endl;
	return 0;
}