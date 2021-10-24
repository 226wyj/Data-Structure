#include <iostream>

#include "Stack.h"

using std::cout;
using std::endl;


Stack::Stack(int size) {
	stackSize = size;
	stack = new int[size]();	
	length = 0;
}

Stack::~Stack() {
	delete [] stack;
}

// 获取栈的最大容量
int Stack::getStackSize() {
	return stackSize;
}

// 获取栈内元素个数
int Stack::getLength() {
	return length;
}

// 入栈
int Stack::push(int data) {
	if (this->getLength() < this->getStackSize()) {
		for (int i = this->getStackSize() - 1; i > 0; i--) {
			stack[i] = stack[i - 1];
		}
		stack[0] = data;
		this->length++;	// 插入新元素后同步更新栈内元素的个数
		return 1;
	}
	else {
		cout << "Error! Stack Full!" << endl;
		return -1;
	}
}

// 出栈
int Stack::pop() {
	if (this->getLength() == 0) {
		cout << "Error! Stack Empty!" << endl;
		return -1;
	}
	else {
		int result = stack[0];
		for (int i = 0; i < this->getStackSize() - 1; i++) {
			stack[i] = stack[i + 1];
		}
		this->length--;
		return result;
	}
}

// 展示栈中的内容
void Stack::showStack() {
	cout << "head [ ";
	for (int i = 0; i < this->getLength(); i++) {
		cout << this->stack[i] << " ";
	}
	cout << "] tail" << endl;
}