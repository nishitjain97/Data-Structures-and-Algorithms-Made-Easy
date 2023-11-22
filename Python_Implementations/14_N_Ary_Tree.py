from typing import List

class NAryTree:
    def __init__(self, data_val:int) -> None:
        self.data_val = data_val
        self.children = []

    def insert_node(self, data_val:int) -> None:
        self.children.append(NAryTree(data_val))

    def print_tree(self) -> List[int]:
        output = []

        if self is not None:
            output.append(self.data_val)
        else:
            return
        
        for child in self.children:
            output += child.print_tree()

        return output
    
if __name__ == '__main__':
    tree = NAryTree(1)
    
    for i in range(2, 7):
        tree.insert_node(i)

    tree.children[2].insert_node(7)
    tree.children[3].insert_node(8)
    tree.children[3].insert_node(9)
    tree.children[4].insert_node(10)
    tree.children[4].insert_node(11)
    tree.children[4].insert_node(12)
    tree.children[5].insert_node(13)
    tree.children[4].children[1].insert_node(14)
    tree.children[4].children[1].insert_node(156)

    print(tree.print_tree())