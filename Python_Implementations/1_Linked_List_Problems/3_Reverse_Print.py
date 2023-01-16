class Node:
    def __init__(self, data_val:str=None) -> None:
        self.data_val = data_val
        self.next_val = None

class LinkedList:
    def __init__(self) -> None:
        self.head_val = None

    def insert_end(self, data_val:str=None) -> None:
        new_node = Node(data_val)

        if self.head_val is None:
            self.head_val = new_node
            return

        itr_val = self.head_val

        while itr_val.next_val is not None:
            itr_val = itr_val.next_val

        itr_val.next_val = new_node

        return

    def print_list(self) -> None:
        if self.head_val is None:
            return

        itr_val = self.head_val

        while itr_val.next_val is not None:
            print(itr_val.data_val, '-> ', end="")
            itr_val = itr_val.next_val

        print(itr_val.data_val)

        return

    def print_reverse_list(self) -> None:
        self.__reverse_assist(self.head_val)

    def __reverse_assist(self, root:Node) -> None:
        if root is None:
            return

        self.__reverse_assist(root.next_val)
        
        if root == self.head_val:
            print(root.data_val)
        else:
            print(root.data_val, '-> ', end='')

        return

if __name__ == '__main__':
    ll = LinkedList()

    for char in "Nishit":
        ll.insert_end(char)

    ll.print_list()
    ll.print_reverse_list()