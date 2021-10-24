struct Node {
	int data;
	Node* next;
};

class LinkedStack {
private:
	Node* head;
	int length;

public:
	LinkedStack();

	~LinkedStack();

	Node* getHead();

	int getLength();

	// 入栈
	void push(int data);

	// 出栈
	int pop();

	// 展示栈中内容
	void showStack();
};
