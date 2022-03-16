from typing import Optional

class node:
    def __init__(self, val = 0, next = None):
        self.val = val 
        self.next = next
    
class linkedList:
    def __init__(self):
        self.__head = None
        self.__tail = None
    
    def contains(self, key: int) -> bool:
        curr = self.__head
        while curr is not None:
            if curr.val == key:
                return True
            curr = curr.next
        return False

    def addAtTail(self, key: int) -> None:
        newTail = node(val = key)
        if (self.__head == self.__tail) and (self.__tail is None):
            self.__head = self.__tail = newTail
            return
        
        self.__tail.next = newTail
        self.__tail = newTail

    def __deleteAtHead(self) -> None:
        if (self.__head == self.__tail) and (self.__head is None):
            return
        
        delNode = self.__head
        if (self.__head == self.__tail) and (self.__head is not None):
            self.__head = self.__tail = None
        else:
            self.__head = self.__head.next
        
        delNode.next = None
    
    def __deleteAtTail(self) -> None:
        if (self.__head == self.__tail) and (self.__head is None):
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
        
    def deleteAtMiddle(self, key: int) -> None:
        # Linked List Empty
        if (self.__head == self.__tail) and self.__head is None:
            return
        
        prevNode = self.__head

        if prevNode.val == key:
            self.__deleteAtHead(); 
            return
        
        found = False

        while prevNode.next is not None:
            if (prevNode.next.val == key):
                found = True
                break
            prevNode = prevNode.next
        
        if not found: return

        if prevNode.next == self.__tail:
            self.__deleteAtTail()
        else:
            delNode = prevNode.next
            prevNode.next = delNode.next
            delNode.next = None


    def printSLL(self) -> None: 
        curr = self.__head
        while curr is not None:
            print((curr.val), end = " -> ")
            curr = curr.next
        print("END")

class MyHashSet:
    def __init__(self, _tsize:int = 10): # Use a Prime Number like 499 for best performance
        self.tsize = _tsize
        self.llmap = [None] * (self.tsize)

        for i in range(self.tsize):
            self.llmap[i] = linkedList()
    
    def add(self, key: int) -> None:
        hashAddr = (key % self.tsize)

        if not self.llmap[hashAddr].contains(key):
            self.llmap[hashAddr].addAtTail(key)
    
    def remove(self, key: int) -> None: 
        hashAddr = (key % self.tsize)

        if self.llmap[hashAddr].contains(key):
            self.llmap[hashAddr].deleteAtMiddle(key)
    
    def contains(self, key: int) -> bool:
        return self.llmap[key % self.tsize].contains(key)

    def printLLM(self) -> None: 
        for i in range(self.tsize):
            print(i, end = ": ")
            self.llmap[i].printSLL()
        print()

if __name__ == '__main__':
    hs1 = MyHashSet(_tsize = 13)

    data = [185, 96, 167, 34, 161, 24, 47, 58, 187, 88, 
            63, 31, 138, 78, 145, 139, 70, 65, 56, 79, 
            141, 133, 127, 28, 169, 27, 179, 67, 110, 37, 
            111, 177, 121, 199, 144, 132, 60, 134, 68, 35, 
            162, 118, 100, 123, 90, 57, 42, 93, 20, 55, 
            163, 71, 148, 130, 27, 43, 133, 114, 25, 47, 
            33, 152, 151, 103, 83, 134, 38, 188, 52, 81, 
            66, 154, 90, 192, 22, 144, 60, 102, 20, 23, 
            100, 63, 87, 31, 131, 169, 193, 62, 77, 122, 
            178, 200, 96, 196, 173, 58, 35, 24, 194, 165]

    
    for element in data:
        hs1.add(element)
    
    hs1.printLLM()