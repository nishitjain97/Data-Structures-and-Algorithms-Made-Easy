class Stack:
    def __init__(self) -> None:
        self.data = []

    def push(self, data_val:str) -> None:
        self.data.append(data_val)

    def pop(self) -> str:
        if len(self.data) == 0:
            return None
        return self.data.pop()

    def is_empty(self) -> bool:
        if len(self.data) == 0:
            return True
        return False

def reverse_stack(s:Stack) -> None:
    if s.is_empty():
        return

    data = s.pop()
    reverse_stack(s)
    insert_at_bottom(s, data)

def insert_at_bottom(s:Stack, data_val:str) -> None:
    if s.is_empty():
        s.push(data_val)
        return

    data = s.pop()
    insert_at_bottom(s, data_val)
    s.push(data)

if __name__ == '__main__':
    s = Stack()

    for i in range(1, 11):
        print("Pushing", i)
        s.push(i)

    reverse_stack(s)
    
    data = s.pop()

    while data is not None:
        print("Popping", data)
        data = s.pop()