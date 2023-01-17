class Stack:
    def __init__(self) -> None:
        self.data = []

    def push(self, char:str) -> None:
        self.data.append(char)

    def pop(self) -> str:
        if len(self.data) == 0:
            return None
        
        return self.data.pop()

    def peek(self) -> str:
        if len(self.data) == 0:
            return None

        return self.data[-1]

if __name__ == '__main__':
    st = Stack()

    # inp = "mississippi"
    inp = "careermonk"

    i = 0

    while i < len(inp):
        if st.peek() is None:
            st.push(inp[i])
            i += 1
        elif st.peek() != inp[i]:
            st.push(inp[i])
            i += 1
        else:
            while i < len(inp) and st.peek() == inp[i]:
                i += 1
            st.pop()

    print(st.data)