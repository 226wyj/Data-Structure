from typing import Optional

class Queue:
    def __init__(self, queue=[]) -> None:
        self.queue = queue
    
    def is_empty(self) -> int:
        return len(self.queue) == 0
    
    def get_size(self) -> int:
        return len(self.queue)
    
    def en_queue(self, num) -> None:
        self.queue.append(num)

    def de_queue(self) -> Optional[int]:
        if self.is_empty():
            print("Queue is empty, nothing to return.")
            return None
        else:
            target = self.queue[0]
            del self.queue[0]
            return target
        
    def print_queue(self):
        print(self.queue)