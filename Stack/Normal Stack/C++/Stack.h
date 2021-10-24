#ifndef STACK_H
#define STACK_H

class Stack {
private:
	int* stack;		// 指向栈
	int stackSize;	// 栈的最大容量
	int length;		// 栈内元素的个数
public:
	Stack(int size);

	~Stack();

	// 获取栈的最大容量
	int getStackSize();

	// 获取栈内元素个数
	int getLength();

	// 入栈
	int push(int data);
	// 出栈
	int pop();

	// 展示栈中的内容
	void showStack();
};

#endif