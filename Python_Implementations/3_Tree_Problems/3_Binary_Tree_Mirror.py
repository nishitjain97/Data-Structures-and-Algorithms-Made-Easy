"""
Tree Implementation
"""
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
            root = q.dequeue()

            if root.left_child is not None:
                q.enqueue(root.left_child)
            else:
                root.left_child = BinaryTree(data_val)
                return
            
            if root.right_child is not None:
                q.enqueue(root.right_child)
            else:
                root.right_child = BinaryTree(data_val)
                return
            
    def print_tree(self) -> None:
        if self is None:
            print([])
            return
        
        q = Queue()
        q.enqueue(self)
        result = []

        while not q.is_empty():
            root = q.dequeue()
            result.append(root.data_val)

            if root.left_child is not None:
                q.enqueue(root.left_child)

            if root.right_child is not None:
                q.enqueue(root.right_child)

        print(result)

    def mirror_tree(self) -> None:
        if self is None:
            return
        
        if self.left_child is not None:
            self.left_child.mirror_tree()

        if self.right_child is not None:
            self.right_child.mirror_tree()

        self.left_child, self.right_child = self.right_child, self.left_child

def check_mirrors(tree1, tree2) -> bool:
    if tree1 is None and tree2 is None:
        return True
    
    if tree1 is None or tree2 is None:
        return False
    
    if tree1.data_val != tree2.data_val:
        return False
    
    return check_mirrors(tree1.left_child, tree2.right_child) and check_mirrors(tree1.right_child, tree2.left_child)

"""
Queue Implementation
"""
class Node:
    def __init__(self, data_val:BinaryTree) -> None:
        self.data_val = data_val
        self.next = None
        self.prev = None

class Queue:
    def __init__(self) -> None:
        self.front = None
        self.rear = None

    def enqueue(self, data_val:int) -> None:
        new_node = Node(data_val)

        if self.front is None:
            self.front = new_node
            self.rear = new_node

        else:
            self.rear.next = new_node
            new_node.prev = self.rear
            self.rear = self.rear.next

    def dequeue(self) -> int:
        if self.front is None:
            return None
        
        data = self.front.data_val

        self.front = self.front.next

        if self.front is not None:
            self.front.prev = None
        else:
            self.rear = None

        return data
    
    def is_empty(self) -> bool:
        if self.front is None:
            return True
        return False
    
if __name__ == '__main__':
    tree = BinaryTree(1)

    for i in range(2, 11):
        tree.insert_node(i)

    tree.print_tree()

    tree.mirror_tree()

    tree2 = BinaryTree(1)

    for i in range(2, 11):
        tree2.insert_node(i)

    tree.print_tree()
    tree2.print_tree()

    print(check_mirrors(tree, tree2))