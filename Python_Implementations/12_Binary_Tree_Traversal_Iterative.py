from typing import List

class BinaryTree:
    def __init__(self, data_val:int) -> None:
        self.data_val = data_val
        self.left_child = None
        self.right_child = None

    def insert_node(self, data_val:int) -> None:
        if data_val < self.data_val:
            if self.left_child is None:
                self.left_child = BinaryTree(data_val)
            else:
                self.left_child.insert_node(data_val)
        else:
            if self.right_child is None:
                self.right_child = BinaryTree(data_val)
            else:
                self.right_child.insert_node(data_val)
                
    def pre_order(self) -> List[int]:
        s = Stack()

        root = self
        result = []

        while True:
            while root is not None:
                result.append(root.data_val)
                s.push(root)
                root = root.left_child
            
            if s.is_empty():
                break

            root = s.pop()
            
            root = root.right_child

        return result

    def in_order(self) -> List[int]:
        s = Stack()

        root = self
        result = []

        while True:
            while root is not None:
                s.push(root)
                root = root.left_child

            if s.is_empty():
                break

            root = s.pop()
            result.append(root.data_val)
            root = root.right_child

        return result
    
    def post_order(self) -> List[int]:
        s = Stack()
        previous = None
        root = self
        result = []

        while True:
            while root is not None:
                s.push(root)
                root = root.left_child

            while root is None and not s.is_empty():
                root = s.top()

                if root.right_child is None or root.right_child == previous:
                    result.append(root.data_val)
                    s.pop()
                    previous = root
                    root = None
                else:
                    root = root.right_child

            if s.is_empty():
                break

        return result

class Stack:
    def __init__(self) -> None:
        self.data_val = []

    def push(self, data_val:BinaryTree) -> None:
        self.data_val.append(data_val)

    def pop(self) -> BinaryTree:
        if self.is_empty():
            return None
        return self.data_val.pop()
        
    def is_empty(self) -> bool:
        if len(self.data_val) == 0:
            return True
        return False
    
    def top(self) -> BinaryTree:
        return self.data_val[-1]

if __name__ == '__main__':
    bt = BinaryTree(10)
    bt.insert_node(20)
    bt.insert_node(5)
    bt.insert_node(30)
    
    print(bt.pre_order())
    print(bt.in_order())
    print(bt.post_order())