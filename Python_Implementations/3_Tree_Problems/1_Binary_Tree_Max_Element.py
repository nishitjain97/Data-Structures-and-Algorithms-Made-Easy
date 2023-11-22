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

    def find_max(self) -> int:
        if self is None:
            return None
        
        if self.left_child is not None:
            left_max = self.left_child.find_max()
        else:
            left_max = None

        if self.right_child is not None:
            right_max = self.right_child.find_max()
        else:
            right_max = None

        max_val = self.data_val
        if left_max is not None and left_max > max_val:
            max_val = left_max
        if right_max is not None and right_max > max_val:
            max_val = right_max

        return max_val
    
if __name__ == '__main__':
    tree = BinaryTree(10)
    tree.insert_node(20)
    tree.insert_node(30)
    tree.insert_node(40)
    tree.insert_node(5)

    print(tree.find_max())