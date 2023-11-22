"""
    Binary Search Tree
"""

class Node:
    def __init__(self, data_val:int) -> None:
        self.data_val = data_val
        self.left = None
        self.right = None
        self.parent = None

class BinarySearchTree:
    def __init__(self) -> None:
        self.root = None

    def is_empty(self) -> bool:
        if self.root is None:
            return True
        return False

    def search(self, key:int) -> Node:
        if self.root is None:
            return None

        root = self.root

        while root:
            if key < root.data_val:
                root = root.left
            elif key > root.data_val:
                root = root.right
            elif key == root.data_val:
                return root

        return None

    def insert(self, key:int) -> None:
        new_node = Node(key)

        if self.root is None:
            self.root = new_node
            return
            
        root = self.root
        parent = None

        while root:
            parent = root
            if key <= root.data_val:
                root = root.left
            else:
                root = root.right

        if key <= parent.data_val:
            parent.left = new_node
        else:
            parent.right = new_node

        new_node.parent = parent

        return

if __name__ == '__main__':
    bst = BinarySearchTree()

    bst.insert(10)
    bst.insert(20)