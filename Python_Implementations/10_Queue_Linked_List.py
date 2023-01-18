class Node:
    def __init__(self, data_val:int) -> None:
        self.data_val = data_val
        self.next_val = None

class Queue:
    def __init__(self) -> None:
        self.head_val = None
        self.tail_val = None

    def enq(self, data_val:int) -> None:
        new_node = Node(data_val=data_val)

        if self.head_val is None:
            self.head_val = new_node
            self.tail_val = new_node
        else:
            self.tail_val.next_val = new_node
            self.tail_val = new_node

        return

    def deq(self) -> int:
        if self.head_val is None:
            return None

        data = self.head_val.data_val
        self.head_val = self.head_val.next_val

        return data

if __name__ == '__main__':
    q = Queue()

    for i in range(10):
        q.enq(i)

    for j in range(20):
        print(q.deq())