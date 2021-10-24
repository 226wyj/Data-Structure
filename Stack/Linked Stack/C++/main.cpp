#include <iostream>

#include "LinkedStack.h"

using namespace std;


int main() {
	LinkedStack myStack = LinkedStack();

	cout << "Pushing 0, 1, 2, 3, 4 into the linked stack:" << endl;
	for (int i = 0; i < 5; i++)
		myStack.push(i);
	cout << "Linked Stack:" << endl;
	myStack.showStack();

	cout << "Length:\t" << myStack.getLength() << endl;
	
	cout << "Pop:\t" << myStack.pop() << endl;
	
	cout << "Linked Stack:" << endl;
	myStack.showStack();
	
	cout << "Length:\t" << myStack.getLength() << endl;
	return 0;
}