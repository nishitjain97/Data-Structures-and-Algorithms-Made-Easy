class Node:
    def __init__(self, data_val: str) -> None:
        self.data_val = data_val
        self.next_val = None

class LinkedList:
    def __init__(self) -> None:
        self.head_val = None

    def insert_end(self, data_val:str) -> None:
        new_node = Node(data_val)

        if self.head_val is None:
            self.head_val = new_node
            return

        itr_val = self.head_val

        while itr_val.next_val is not None:
            itr_val = itr_val.next_val

        itr_val.next_val = new_node
        return

    def nth_node_end(self, n:int) -> Node:
        if self.head_val is None:
            print("No nodes in list")
            return None
        elif n == 0:
            return None

        itr_val = self.head_val

        while n > 0:
            itr_val = itr_val.next_val
            n -= 1

            if n > 0 and itr_val is None:
                print("Not enough elements in list")
                return None

        cur_pointer = self.head_val

        while itr_val is not None:
            cur_pointer = cur_pointer.next_val
            itr_val = itr_val.next_val

        return cur_pointer 

    def print_list(self) -> None:
        if self.head_val is None:
            return

        itr_val = self.head_val

        while itr_val.next_val is not None:
            print(itr_val.data_val, '-> ', end='')
            itr_val = itr_val.next_val

        print(itr_val.data_val)

        return

if __name__ == '__main__':
    ll = LinkedList()
    ll.insert_end("Nishit")
    ll.insert_end("Jain")
    ll.insert_end("is")
    ll.insert_end("the")
    ll.insert_end("best")
    ll.print_list()
    for i in range(10):
        node = ll.nth_node_end(i)

        if node is None:
            continue
        else:
            print(i, node.data_val)