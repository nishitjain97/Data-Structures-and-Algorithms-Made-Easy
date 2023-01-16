class Stack:
    def __init__(self, max_size:int=10) -> None:
        self.data = [None for i in range(max_size)]
        self.max_size = max_size
        self.size = 0

    def push(self, data_val:int) -> bool:
        if self.size == self.max_size:
            return False

        self.data[self.size] = data_val
        self.size += 1

        return True

    def pop(self) -> int:
        if self.size == 0:
            return None

        self.size -= 1
        data = self.data[self.size]

        return data

    def top(self) -> int:
        if self.size == 0:
            return None

        return self.data[self.size-1]

    def get_size(self) -> int:
        return self.size

    def is_empty_stack(self) -> bool:
        if self.size == 0:
            return True

        return False

    def is_full_stack(self) -> bool:
        if self.size == self.max_size:
            return True
        return False

if __name__ == '__main__':
    s = Stack(3)

    for i in range(10):
        s.push(i)

    print(s.data)
    
    print(s.top())
    print(s.get_size())

    for i in range(10):
        print(s.pop())
    
    print(s.data)

    print(s.get_size())