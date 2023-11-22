from typing import List

class BinaryTree:
    def __init__(self, data_val:int) -> None:
        self.data_val = data_val
        self.left_child = None
        self.right_child = None

    def insert_node(self, data_val:int) -> None:
        q = Queue()

        if self is None:
            self = BinaryTree(data_val)
            return
        
        q.enqueue(self)
        
        while not q.is_empty():
            temp = q.dequeue()

            if temp.left_child is not None:
                q.enqueue(self.left_child)
            else:
                temp.left_child = BinaryTree(data_val)
                return

            if temp.right_child is not None:
                q.enqueue(self.right_child)
            else:
                temp.right_child = BinaryTree(data_val)
                return

class Node:
    def __init__(self, data_val:BinaryTree) -> None:
        self.data_val = data_val
        self.next = None
        self.prev = None

class Queue:
    def __init__(self) -> None:
        self.front = None
        self.rear = None

    def enqueue(self, data_val:BinaryTree) -> None:
        new_node = Node(data_val)

        if self.front is None:
            self.front = new_node
            self.rear = new_node

        else:
            self.rear.next = new_node
            new_node.prev = self.rear
            self.rear = new_node

    def dequeue(self) -> BinaryTree:
        if self.front is None:
            return None
        
        data = self.front.data_val

        self.front = self.front.next

        if self.front is not None:
            self.front.prev = None

        return data
    
    def is_empty(self) -> bool:
        if self.front is None:
            return True
        return False
    
if __name__ == '__main__':
    tree = BinaryTree(1)
    tree.insert_node(2)
    tree.insert_node(3)
    tree.insert_node(4)
    tree.insert_node(5)
    tree.insert_node(6)
    tree.insert_node(7)

    print(tree.data_val)
    print(tree.left_child.data_val)
    print(tree.right_child.data_val)
    print(tree.left_child.left_child.data_val)
    print(tree.left_child.right_child.data_val)
    print(tree.right_child.left_child.data_val)
    print(tree.right_child.right_child.data_val)