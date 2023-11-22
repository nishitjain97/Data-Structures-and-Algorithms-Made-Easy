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
        output_list = [self.data_val]

        if self.left_child is not None:
            output_list += self.left_child.pre_order()
        if self.right_child is not None:
            output_list += self.right_child.pre_order()

        return output_list

    def in_order(self) -> List[int]:
        output_list = []

        if self.left_child is not None:
            output_list += self.left_child.in_order()
        output_list.append(self.data_val)
        if self.right_child is not None:
            output_list += self.right_child.in_order()

        return output_list

    def post_order(self) ->  List[int]:
        output_list = []

        if self.left_child is not None:
            output_list += self.left_child.post_order()

        if self.right_child is not None:
            output_list += self.right_child.post_order()

        output_list.append(self.data_val)

        return output_list

if __name__ == '__main__':
    bt = BinaryTree(10)
    bt.insert_node(20)
    bt.insert_node(5)
    bt.insert_node(30)
    
    print(bt.pre_order())
    print(bt.in_order())
    print(bt.post_order())