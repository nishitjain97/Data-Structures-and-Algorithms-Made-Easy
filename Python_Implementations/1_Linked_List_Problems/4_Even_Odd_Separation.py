class Node:
    def __init__(self, data_val:int) -> None:
        self.data_val = data_val
        self.next_val = None

class LinkedList:
    def __init__(self) -> None:
        self.head_val = None

    def insert_end(self, data_val:int) -> None:
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

    def rearrange_nodes(self) -> None:
        if self.head_val is None:
            return

        even_nodes = None
        even_itr = None
        odd_nodes = None
        odd_itr = None

        itr_val = self.head_val

        while itr_val is not None:
            if itr_val.data_val % 2 == 0:
                if even_nodes is None:
                    even_nodes = itr_val
                    even_itr = itr_val
                else:
                    even_itr.next_val = itr_val
                    even_itr = even_itr.next_val

            else:
                if odd_nodes is None:
                    odd_nodes = itr_val
                    odd_itr = itr_val
                else:
                    odd_itr.next_val = itr_val
                    odd_itr = odd_itr.next_val

            itr_val = itr_val.next_val

        if even_nodes is not None:
            self.head_val = even_nodes
            even_itr.next_val = odd_nodes
        else:
            self.head_val = odd_nodes

        if odd_nodes is not None:
            odd_itr.next_val = None

        return
                    
        

if __name__ == '__main__':
    ll = LinkedList()
    
    for i in range(1, 11):
        ll.insert_end(i)

    ll.print_list()

    ll.rearrange_nodes()

    ll.print_list()