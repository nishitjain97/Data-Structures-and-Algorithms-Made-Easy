class Node:
    def __init__(self, dataval:str=None):
        self.dataval = dataval
        self.nextval = None

class LinkedList:
    def __init__(self):
        self.headval = None

    def listprint(self) -> None:
        printval = self.headval

        while printval is not None:
            print(printval.dataval, end=' ')
            if printval.nextval is not None:
                print('->', end=' ')
            printval = printval.nextval

        print()

    def insert_beginning(self, dataval:str) -> None:
        new_node = Node(dataval)
        new_node.nextval = self.headval
        self.headval = new_node
        
    def insert_end(self, dataval:str) -> None:
        new_node = Node(dataval)

        if self.headval is None:
            self.headval = new_node
            return

        itr_val = self.headval

        while itr_val.nextval is not None:
            itr_val = itr_val.nextval
            
        itr_val.nextval = new_node
        return

    def remove_key(self, key:str) -> str:
        headval = self.headval

        if headval.dataval == key:
            self.headval = headval.nextval
            headval = None
            return
        
        while headval is not None:
            if headval.dataval == key:
                break
            prev = headval
            headval = headval.nextval

        if headval == None:
            return
        
        prev.nextval = headval.nextval
        headval = None

if __name__ == '__main__':
    list1 = LinkedList()
    list1.headval = Node("Monday")
    list1.headval.nextval = Node("Tuesday")
    list1.listprint()
    list1.insert_beginning("Sunday")
    list1.listprint()
    list1.insert_end("Wednesday")
    list1.listprint()
    list1.remove_key("Monday")
    list1.listprint()