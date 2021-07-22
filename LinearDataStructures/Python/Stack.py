class Stack:
    def __init__(self, stack=[]) -> None:
        self.stack = stack
    
    def is_empty(self):
        return len(self.stack) == 0

    def get_size(self):
        return len(self.stack)

    def push(self, num):
        self.stack.append(num)
    
    def pop(self):
        if self.is_empty():
            return None
        else:
            target = self.stack[-1]
            del self.stack[-1]
            return target
    
    def peek(self):
        if self.is_empty():
            return None
        else:
            return self.stack[-1]
    
    def print_stack(self):
        for i in range(self.get_size() - 1, -1, -1):
            print(self.stack[i])

if __name__ == '__main__':
    stack = Stack()
    print("0~5入栈:")
    for i in range(0, 5):
        stack.push(i)
    
    print('栈的容量: ', stack.get_size())
    stack.print_stack()

    print('查看栈顶元素:')
    print('栈顶元素: ', stack.peek())
    stack.print_stack()

    print('栈顶元素出栈:')
    print('栈顶元素: ', stack.pop())
    stack.print_stack()