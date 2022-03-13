import os
from typing import Optional
cwd = os.path.dirname(__file__)

class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val 
        self.next = next
    
def makeSLL_string(data: str) -> Optional[ListNode]:
    if len(data) == 0:
        return None
    
    dummyHead = ListNode()
    curr = dummyHead

    for element in list(map(int, data.split())):
        newNode = ListNode(val = element)
        curr.next = newNode
        curr = curr.next
    
    return dummyHead.next   # dummyHead will be destroyed by the Python Garbage Collector

def printSLL(head: Optional[ListNode]) -> None: 
    curr = head

    while curr is not None: 
        print((curr.val), end = " -> ")
        curr = curr.next
    print("END")

def middleNode(head: Optional[ListNode]) -> Optional[ListNode]: 
    a = head
    b = head

    while b is not None and b.next is not None: 
        a = a.next
        b = b.next.next
    
    return a 


if __name__ == '__main__': 
    nInputs = 5

    for i in range(1, nInputs + 1): 
        fname = "input{number}.txt"
        fpath = os.path.join(cwd, fname.format(number = i))
        
        print("======== TestCase {number} ========".format(number = i))
        try: 
            with open(fpath, "r") as fileHandle: 
                #  ===== START =====
                data = fileHandle.readline().strip()

                print(data)

                head = makeSLL_string(data)
                middleAddr = middleNode(head)

                print(middleAddr)
                print((middleAddr.val) if middleAddr is not None else "Null")
                
                #  ===== END =====
        except FileNotFoundError:
            print("Cannot Open the test case")
            break