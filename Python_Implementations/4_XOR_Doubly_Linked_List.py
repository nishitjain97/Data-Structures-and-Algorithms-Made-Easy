import ctypes

class Node:
    def __init__(self, data_val:str):
        self.data_val = data_val
        self.next_val = 0

class XORLL:
    def __init__(self):
        self.head_val = None

        # List to store nodes as without a reference pointing
        # to the node, Python will use GC to destroy it
        self.__nodes = []

    def insert_start(self, data_val:str) -> None:
        new_node = Node(data_val)

        if self.head_val is None:
            self.head_val = new_node
        else:
            self.head_val.next_val = id(new_node) ^ self.head_val.next_val
            new_node.next_val = id(self.head_val)
            self.head_val = new_node

        self.__nodes.append(new_node)

        return 

    def insert_end(self, data_val:str) -> None:
        new_node = Node(data_val)

        if self.head_val is None:
            self.head_val = new_node
        else:
            prev_id = 0
            itr_val = self.head_val
            next_id = 1

            while next_id:
                next_id = prev_id ^ itr_val.next_val

                if next_id:
                    prev_id = id(itr_val)
                    itr_val = self.__type_cast(next_id)
                else:
                    itr_val.next_val = prev_id ^ id(new_node)
                    new_node.next_val = id(itr_val)

        self.__nodes.append(new_node)

        return

    def print_list(self) -> None:
        if self.head_val is not None:
            prev_id = 0
            itr_val = self.head_val
            next_id = 1
            print(itr_val.data_val, '-> ', end='')

            while next_id:
                next_id = prev_id ^ itr_val.next_val

                if next_id:
                    prev_id = id(itr_val)
                    itr_val = self.__type_cast(next_id)
                    print(itr_val.data_val, '-> ', end='')
                else:
                    print()
                    return

            print()
        else:
            return

    def __type_cast(self, id):
        return ctypes.cast(id, ctypes.py_object).value

if __name__ == '__main__':
    xll = XORLL()
    xll.insert_start("Jain")
    xll.insert_start("Nishit")
    xll.insert_end("is")
    xll.insert_end("the")
    xll.print_list()