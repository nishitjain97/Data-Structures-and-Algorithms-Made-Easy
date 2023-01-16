class Node:
    def __init__(self, data_val:str) -> None:
        self.data_val = data_val
        self.next_val = None

class LinkedList:
    def __init__(self) -> None:
        self.head_val = None

    def insert_end(self, data_val: str) -> None:
        new_node = Node(data_val=data_val)

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
            print(itr_val.data_val, '-> ', end='')
            itr_val = itr_val.next_val

        print(itr_val.data_val)

        return

    def reverse_list(self) -> None:
        self.head_val = self.__rec_reverse(root=self.head_val)

    def __rec_reverse(self, root:Node) -> Node:
        if root is None:
            return None

        if root.next_val is None:
            return root

        next_node = root.next_val
        root.next_val = None
        reversed_remaining = self.__rec_reverse(root=next_node)
        next_node.next_val = root
        return reversed_remaining

if __name__ == '__main__':
    ll = LinkedList()

    ll.insert_end("Nishit")
    ll.insert_end("Jain")
    ll.insert_end("is")
    ll.insert_end("the")
    ll.insert_end("best")

    ll.print_list()
    ll.reverse_list()
    ll.print_list()