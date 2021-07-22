class Queue:
    def __init__(self, queue=[]) -> None:
        self.queue = queue
    
    def is_empty(self):
        return len(self.queue) == 0
    
    def get_size(self):
        return len(self.queue)
    
    def en_queue(self, num):
        self.queue.append(num)

    def de_queue(self):
        if self.is_empty():
            print("Queue is empty, nothing to return.")
            return None
        else:
            target = self.queue[0]
            del self.queue[0]
            return target
        
    def print_queue(self):
        print(self.queue)

if __name__ == '__main__':
    queue = Queue()
    print("0~4依次入队列:")
    for i in range(0, 5):
        queue.en_queue(i)
    queue.print_queue()

    print("队列容量: ", queue.get_size())

    print('队头元素出队列:')
    print('队头元素: ', queue.de_queue())
    queue.print_queue()