#include <iostream>

#include "Stack.h"

using namespace std;

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