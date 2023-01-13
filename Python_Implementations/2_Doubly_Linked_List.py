class Node:
    def __init__(self, data_val:str = None):
        self.data_val = data_val
        self.next_val = None
        self.prev_val = None

class DoublyLL:
    def __init__(self):
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
        new_node.prev_val = itr_val
        return

    def insert_start(self, data_val:str) -> None:
        new_node = Node(data_val)
        
        if self.head_val is None:
            self.head_val = new_node
            return

        new_node.next_val = self.head_val
        self.head_val.prev_val = new_node
        self.head_val = new_node

        return

    def delete_key(self, key:str) -> None:
        itr_val = self.head_val

        if itr_val.data_val == key:
            self.head_val = itr_val.next_val
            itr_val = None
            return

        while itr_val.data_val is not None:
            if itr_val.data_val == key:
                itr_val.prev_val.next_val = itr_val.next_val

                if itr_val.next_val is not None:
                    itr_val.next_val.prev_val = itr_val.prev_val
                itr_val = None

                break
            itr_val = itr_val.next_val

        return

    def print_list(self) -> None:
        itr_val = self.head_val

        while itr_val is not None:
            print(itr_val.data_val, end=' ')

            if itr_val.next_val is not None:
                print('->', end=' ')

            itr_val = itr_val.next_val

        print()

if __name__ == '__main__':
    dll = DoublyLL()
    dll.insert_start("Nishit")
    dll.insert_end("Jain")
    dll.insert_end("is")
    dll.insert_end("best")
    dll.print_list()
    dll.insert_start("Mr.")
    dll.print_list()
    dll.delete_key("Mr.")
    dll.print_list()
    dll.delete_key("Jain")
    dll.print_list()
    dll.delete_key("best")
    dll.print_list()