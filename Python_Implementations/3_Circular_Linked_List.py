class Node:
    def __init__(self, data_val:str = None):
        self.data_val = data_val
        self.next_val = self

class CircularLL:
    def __init__(self):
        self.head_val = None

    def insert_end(self, data_val:str) -> None:
        new_node = Node(data_val)

        if self.head_val == None:
            self.head_val = new_node
            return

        itr_val = self.head_val

        while itr_val.next_val is not self.head_val:
            itr_val = itr_val.next_val

        itr_val.next_val = new_node
        new_node.next_val = self.head_val

        return

    def insert_start(self, data_val:str) -> None:
        new_node = Node(data_val)

        if self.head_val is None:
            self.head_val = new_node
            return

        itr_val = self.head_val

        while itr_val.next_val is not self.head_val:
            itr_val = itr_val.next_val

        itr_val.next_val = new_node
        new_node.next_val = self.head_val
        self.head_val = new_node

        return 

    def delete_node(self, key:str) -> None:
        if self.head_val is None:
            return

        itr_val = self.head_val
        
        if self.head_val.data_val == key:
            while itr_val.next_val is not self.head_val:
                itr_val = itr_val.next_val

            itr_val.next_val = self.head_val.next_val
            self.head_val = self.head_val.next_val
            return

        while itr_val.next_val is not self.head_val:
            prev = itr_val
            itr_val = itr_val.next_val

            if itr_val.data_val == key:
                break

        if itr_val.next_val == self.head_val and itr_val.data_val != key:
            return

        prev.next_val = itr_val.next_val
        itr_val = None
        return

        

    def print_list(self) -> None:
        itr_val = self.head_val

        while itr_val.next_val is not self.head_val:
            print(itr_val.data_val, '-> ', end='')
            itr_val = itr_val.next_val

        print(itr_val.data_val)


if __name__ == '__main__':
    cll = CircularLL()
    cll.insert_end("is")
    cll.insert_start("Jain")
    cll.insert_end("the")
    cll.insert_start("Nishit")
    cll.insert_end("best")
    cll.print_list()
    cll.delete_node("best")
    cll.print_list()
    cll.delete_node("Nishit")
    cll.print_list()
    cll.delete_node("is")
    cll.print_list()