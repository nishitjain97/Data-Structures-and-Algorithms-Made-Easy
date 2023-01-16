class Node:
    def __init__(self, data_val:int=None) -> None:
        self.data_val = data_val
        self.next_val = None
        
class Stack:
    def __init__(self) -> None:
        self.head_val = None

    def push(self, data_val:int) -> None:
        new_node = Node(data_val)

        if self.head_val is None:
            self.head_val = new_node
            return

        new_node.next_val = self.head_val
        self.head_val = new_node

        return

    def pop(self) -> int:
        if self.head_val is None:
            return None

        popped_node = self.head_val
        self.head_val = self.head_val.next_val
        popped_node.next_val = None

        return popped_node.data_val

    def peek(self) -> int:
        if self.head_val is None:
            return None

        return self.head_val.data_val

if __name__ == '__main__':
    s = Stack()

    for i in range(10):
        print("Pushing", i)
        s.push(i)

    for i in range(12):
        print("Popping")
        print(s.pop())