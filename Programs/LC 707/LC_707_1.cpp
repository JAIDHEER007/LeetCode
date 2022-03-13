// Implementing using Single Linked List

// Runtime: 32ms
// Faster Than: 98.33%
// Memorey Usage: 19.8 Mb
// Less Than: 27.17%

#include<iostream>
#include<vector>

using namespace std;

class node{
    public:
        int val; 
        node* next; 
        
        node(){
            val = 0; 
            next = NULL; 
        }
        node(int value){
            val = value; 
            next = NULL; 
        }
        node(int value, node* nextPtr){
            val = value; 
            next = nextPtr; 
        }
}; 

class MyLinkedList : public node{
    private:
        node* head; 
        node* tail; 
    public:
        MyLinkedList(){
            head = tail = NULL; 
        }

        int get(int); 

        void addAtHead(int); 
        void addAtTail(int); 
        void addAtIndex(int, int);
        
        void deleteAtHead(); 
        void deleteAtTail(); 
        void deleteAtIndex(int);
        
        void printSLL(void);   
};

int MyLinkedList::get(int index){
    int pIndex = 0; // Possible Index
    node* curr = head; 

    while(curr){
        if(pIndex == index)
            return (curr->val); 
        ++pIndex; 
        curr = curr->next; 
    }

    return -1; 
}

void MyLinkedList::addAtHead(int val){
    node* newHead = new node(val); 
    if((head == tail) && (head == NULL)){ // Linked List is Empty
        head = tail = newHead;            // Both Head and Tail pointers will point to the same node
        return; 
    }

    // Steps to attach the new head

    // newHead's next should point to old head
    newHead->next = head; 

    // The head pointer will point to the newHead
    head = newHead; 
}

void MyLinkedList::addAtTail(int val){
    node* newTail = new node(val); 
    if((head == tail) && (head == NULL)){ // Linked List is Empty
        head = tail = newTail;            // Both Head and Tail pointers will point to the same node
        return; 
    }

    // Steps to attach the new tail

    // oldTail's next should point to newTail
    tail->next = newTail; 

    // The tail pointer will point to the newTail
    tail = newTail; 
}

void MyLinkedList::addAtIndex(int index, int val){
    // If index = 0
    // Add at head 
    // Let addAtHead() do the job with all the protection 
    if(index == 0){
        addAtHead(val);
        return; 
    }  
    
    // Move to the preceding node of main node 
    node* prevNode = head; 
    int currIndex = 0; 

    while(currIndex != (index - 1)){
        if(prevNode) prevNode = prevNode->next; 
        else break; 
        ++currIndex; 
    }

    // if prevNode is NULL then the index it out of range
    // This is an invalid operation 
    // So we will return by doing nothing
    if(prevNode == NULL) return; 

    // if the previousNode is tail 
    // Then we have to insert at the end of the list
    // Let addAtTail() do its job with all the protection 
    if(prevNode == tail){
        addAtTail(val); 
        return; 
    }

    node* newNode = new node(val); 

    // Attaching the next node to newly created node
    newNode->next = prevNode->next; 
    
    // Changing the prevNode next to newly created node
    prevNode->next = newNode; 
}

void MyLinkedList::deleteAtHead(){
    // Linked List is Empty
    // No Nodes were present
    // Simply do nothing
    if((head == tail) && (head == NULL))
        return; 
    
    node* delNode = head; 
    if((head == tail) && (head != NULL)){ // Linked List Contains one node
        // Make the head and tail as NULL
        head = tail = NULL; 
    }else{
        // Move the head pointer to next node
        head = head->next; 
    }

    // delete the previous head node
    delete delNode; 
}

void MyLinkedList::deleteAtTail(){
    // Linked List is Empty
    // No Nodes were present
    // Simply do nothing
    if((head == tail) && (tail == NULL))
        return; 
    
    node* delNode = tail; 
    if((head == tail) && (tail != NULL)){ // Linked List Contains one node
        // Make the head and tail as NULL
        head = tail = NULL; 
    }else{
        // Move the tail pointer to previous node of tail 
        // Can be done in O(n) time
        // Can be done in O(1) time using double Linked List

        node* curr = head; 
        while(curr->next != delNode)
            curr = curr->next; 

        // Make curr as the new Tail 
        tail = curr; 

        // Remove the connection between new tail and old tail 
        tail->next = NULL;
    }

    // delete the previous tail node
    delete delNode; 
}

void MyLinkedList::deleteAtIndex(int index){
    // if index = 0
    // Delete the head node
    if(index == 0){
        deleteAtHead(); 
        return; 
    }

    // Get to the previous node
    node* prevNode = head; 
    int currIndex = 0; 

    // Move to the previous node of deleting node
    while(currIndex != (index - 1)){
        if(prevNode) prevNode = prevNode->next; 
        else break; 
        ++currIndex; 
    }

    // if prevNode is NULL then the index it out of range
    // This is an invalid operation 
    // So we will return by doing nothing
    if(prevNode == NULL) return; 

    // if the previousNode is tail 
    // Then we have to delete at the end of the list
    // PS Not the tail 
    // We do nothing as we cannot delete the NULL ptr
    if(prevNode == tail)
        return; 
    
    // Want to delete tail 
    // Let deleteAtTail() do its job with all its protection
    if(prevNode->next == tail){
        deleteAtTail(); 
        return; 
    }

    // node that need to be deleted
    node* delNode = prevNode->next; 

    // By pass the delNode by changing the next pointer of prevNode
    prevNode->next = delNode->next; 

    // Isolate the delNode
    delNode->next = NULL; 

    // Delete the delNode and free its memory
    delete delNode; 
}

void MyLinkedList::printSLL(){
    node* curr = head; 
    while(curr){
        cout<<(curr->val)<<" -> "; 
        curr = curr->next; 
    }cout<<"END"<<endl; 
}

// Test Case 2
/*
int main(){
    MyLinkedList sll1; 

    sll1.addAtHead(7); 
    sll1.addAtHead(2); 
    sll1.addAtHead(1);

    sll1.printSLL(); 
    
    sll1.addAtIndex(3, 0); 

    sll1.printSLL(); 

    sll1.deleteAtIndex(2); 

    sll1.printSLL(); 

    sll1.addAtHead(6); 

    sll1.printSLL(); 

    sll1.addAtTail(4); 

    sll1.printSLL(); 

    cout<<sll1.get(4)<<endl; 

    sll1.addAtHead(4); 

    sll1.printSLL();

    sll1.addAtIndex(5, 0); 

    sll1.printSLL(); 

    sll1.addAtHead(6); 

    sll1.printSLL(); 

    return 0; 
} */


// Test Case 8
/* int main(){
    MyLinkedList sll1;

    sll1.addAtHead(2); 

    sll1.printSLL(); 

    sll1.deleteAtIndex(1); 

    sll1.printSLL(); 

    sll1.addAtHead(2); 
    sll1.addAtHead(7); 
    sll1.addAtHead(3); 
    sll1.addAtHead(2); 
    sll1.addAtHead(5);

    sll1.printSLL(); 

    sll1.addAtTail(5);

    sll1.printSLL(); 

    cout<<sll1.get(5)<<endl; 

    sll1.deleteAtIndex(6); 

    sll1.printSLL(); 

    sll1.deleteAtIndex(4); 

    sll1.printSLL();  

    return 0; 
} */

// Test Case 9
int main(){
    MyLinkedList sll1; 
    
    sll1.printSLL(); 

    sll1.addAtHead(0);     
    sll1.printSLL(); 

    sll1.addAtIndex(1, 4); 
    sll1.printSLL(); 

    sll1.addAtTail(8); 
    sll1.printSLL(); 

    sll1.addAtHead(5); 
    sll1.printSLL(); 

    sll1.addAtIndex(4, 3); 
    sll1.printSLL(); 

    sll1.addAtTail(0); 
    sll1.printSLL(); 

    sll1.addAtTail(5); 
    sll1.printSLL(); 

    sll1.addAtIndex(6, 3);
    sll1.printSLL(); 

    sll1.deleteAtIndex(7); 
    sll1.printSLL(); 

    sll1.deleteAtIndex(5); 
    sll1.printSLL(); 

    sll1.addAtTail(4);
    sll1.printSLL(); 

    return 0; 
}