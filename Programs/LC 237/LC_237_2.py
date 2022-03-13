import os
cwd = os.path.dirname(__file__)

from typing import Optional
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

def deleteNode(node: Optional[ListNode]) -> None:
    """
    :type node: ListNode
    :rtype: void Do not return anything, modify node in-place instead.
    """
    nextNode = node.next

    node.val = nextNode.val
    node.next = nextNode.next

    nextNode.next = None

if __name__ == '__main__': 
    nInputs = 2

    for i in range(1, nInputs + 1): 
        fname = "input{number}.txt"
        fpath = os.path.join(cwd, fname.format(number = i))
        
        print("======== TestCase {number} ========".format(number = i))
        try: 
            with open(fpath, "r") as fileHandle: 
                #  ===== START =====
                data = fileHandle.readline().strip()
                delValue = int(fileHandle.readline().strip())


                head = makeSLL_string(data)
                printSLL(head)

                node = head 
                while node is not None:
                    if node.val == delValue: 
                        break
                    node = node.next
                
                deleteNode(node)

                printSLL(head)

                #  ===== END =====
        except FileNotFoundError:
            print("Cannot Open the test case")
            break