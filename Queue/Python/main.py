from queue import Queue

if __name__ == '__main__':
    queue = Queue()
    print("Inqueue 0~4:")
    for i in range(0, 5):
        queue.en_queue(i)
    queue.print_queue()

    print("Length of the queue: ", queue.get_size())

    print('Dequeue:')
    print('Head of the queue: ', queue.de_queue())
    queue.print_queue()