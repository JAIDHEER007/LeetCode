from typing import Optional

class node:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next

class MyLinkedList:

    def __init__(self):
        self.__head = None
        self.__tail = None
    
    def get(self, index: int) -> int:
        curr = self.__head
        pIndex = 0
        
        while curr is not None:
            if pIndex == index: 
                return curr.val
            
            pIndex += 1
            curr = curr.next
        
        return -1
    
    def addAtHead(self, val: int) -> None:
        newNode = node(val = val)

        # If the Linked List is Empty
        if (self.__head == self.__tail) and (self.__head is None):
            self.__head = self.__tail = newNode
            return
        
        newNode.next = self.__head
        
        self.__head = newNode
    
    def addAtTail(self, val: int) -> None:
        newNode = node(val = val)

        # If the Linked List is Empty
        if (self.__head == self.__tail) and (self.__tail is None):
            self.__head = self.__tail = newNode
            return
        
        self.__tail.next = newNode

        self.__tail = newNode
    
    def addAtIndex(self, index: int, val: int) -> None:
        if index == 0:
            self.addAtHead(val)
            return
        
        prevNode = self.__head 
        currIndex = 0

        while currIndex != (index - 1):
            if prevNode is not None:
                prevNode = prevNode.next
            else: break

            currIndex += 1
        
        if prevNode is None: return
    
        if prevNode == self.__tail:
            self.addAtTail(val)
            return
        
        newNode = node(val = val)

        newNode.next = prevNode.next
        prevNode.next = newNode
        
    def deleteAtHead(self) -> None:
        if (self.__head == self.__tail) and (self.__head is None):
            return
        
        delNode = self.__head
        if (self.__head == self.__tail) and (self.__head is not None):
            self.__head = self.__tail = None
        else:
            self.__head = self.__head.next
        
        delNode.next = None
    
    def deleteAtTail(self) -> None:
        if (self.__head == self.__tail) and (self.__tail is None):
            return
        
        delNode = self.__tail
        if (self.__head == self.__tail) and (self.__tail is not None):
            self.__head = self.__tail = None
        else:
            curr = self.__head

            while curr.next != delNode:
                curr = curr.next
            
            self.__tail = curr
            self.__tail.next = None

        delNode.next = None
        
    def deleteAtIndex(self, index: int) -> None:
        if index == 0:
            self.deleteAtHead()
            return
        
        prevNode = self.__head
        currIndex = 0

        while currIndex != (index - 1):
            if prevNode is not None:
                prevNode = prevNode.next
            else: break
            currIndex += 1
        
        if prevNode is None: return

        if prevNode == self.__tail: return

        if prevNode.next == self.__tail: 
            self.deleteAtTail()
            return
        
        delNode = prevNode.next

        prevNode.next = delNode.next
        delNode.next = None
        
    def printSLL(self) -> None:

        curr = self.__head
        while curr is not None:
            print((curr.val), end = " -> ")
            curr = curr.next
        print("END")
    
if __name__ == '__main__':
    sll1 = MyLinkedList()

    sll1.printSLL()

    sll1.addAtHead(553)

    sll1.printSLL()

    sll1.addAtHead(554)
    sll1.addAtHead(555)
    sll1.addAtHead(556)

    sll1.printSLL()
