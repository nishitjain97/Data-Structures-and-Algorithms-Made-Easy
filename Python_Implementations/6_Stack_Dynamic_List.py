class Stack:
    def __init__(self, initial_size:int=10, expand_ratio:float=1.5) -> None:
        self.data = [None for i in range(initial_size)]
        self.max_size = initial_size
        self.size = 0
        self.expand_ratio = expand_ratio

    def push(self, data_val:int) -> None:
        if self.size == self.max_size:
            self.__expand_stack()

        self.data[self.size] = data_val
        self.size += 1
        
        return

    def __expand_stack(self) -> None:
        self.max_size = int(self.max_size * self.expand_ratio)

        data = [None for i in range(self.max_size)]
        
        for i in range(self.size):
            data[i] = self.data[i]

        self.data = data

if __name__ == '__main__':
    s = Stack(5)
    print(s.max_size)

    for i in range(10):
        print("Pushing", i)
        s.push(i)
        print("Size", s.max_size)

    print(s.data)