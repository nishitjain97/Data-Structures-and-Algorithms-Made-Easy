class Queue:
    def __init__(self, max_size:int=10) -> None:
        """
            Initialize Queue DS
        """
        self.data_val = [None for i in range(max_size)]
        self.front = -1
        self.rear = -1
        self.max_size = max_size

    def enq(self, data_val:int) -> bool:
        if self.is_full():
            return False

        if self.front == self.rear and self.front == -1:
            self.front = 0
            self.rear = 0
        else:
            self.rear += 1
            self.rear %= self.max_size

        self.data_val[self.rear] = data_val

        return True

    def is_full(self) -> bool:
        """
            Check if queue is full
        """
        if (self.rear + 1) % self.max_size == self.front:
            return True
        return False

    def deq(self) -> int:
        """
            Function to remove elements from the queue
        """
        if self.is_empty():
            return None
            
        data = self.data_val[self.front]

        if self.front == self.rear:
            self.front = -1
            self.rear = -1
        else:
            self.front += 1
            self.front %= self.max_size

        return data

    def is_empty(self) -> bool:
        if self.front == self.rear and self.front == -1:
            return True
        return False

if __name__ == '__main__':
    q = Queue(5)

    for i in range(6):
        print(q.enq(i))

    print(q.data_val)

    for i in range(10):
        print(q.deq())