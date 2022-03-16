#include<iostream>
#include<vector>

using namespace std; 

class node{
    public:
        int value; 
        node* next; 

        node(){
            value = 0; 
            next = NULL; 
        }
        node(int val){
            value = val; 
            next = NULL; 
        }
        node(int val, node* nextptr){
            value = val; 
            next = nextptr; 
        }
}; 

class linkedList : protected node{
    private: 
        node* head; 
        node* tail; 

        void deleteAtHead(); 
        void deleteAtTail();

    public: 
        linkedList(){
            head = NULL; 
            tail = NULL; 
        }

        bool contains(int); 

        void addAtTail(int); 
 
        void deleteAtMiddle(int);
        
        void printSLL(void); 
};

bool linkedList::contains(int key){
    node* curr = head; 
    while(curr){
        if(curr->value == key) return true; 
        curr = curr->next; 
    }

    return false; 
}

void linkedList::addAtTail(int key){
    node* newTail = new node(key); 
    if((head == tail) && (tail == NULL)){ 
        head = tail = newTail;            
        return; 
    }

    tail->next = newTail; 
    tail = newTail; 
}

void linkedList::deleteAtHead(){
    if((head == tail) && (head == NULL))
        return; 
    
    node* delNode = head; 
    if((head == tail) && (head != NULL)){ 
        head = tail = NULL; 
    }else{
        head = head->next; 
    }

    delete delNode; 
}

void linkedList::deleteAtTail(){
    if((head == tail) && (tail == NULL))
        return; 
    
    node* delNode = tail; 
    if((head == tail) && (tail != NULL)){ 
        head = tail = NULL; 
    }else{
        node* curr = head; 
        while(curr->next != delNode)
            curr = curr->next; 

        tail = curr; 
        tail->next = NULL;
    }

    delete delNode; 
}

void linkedList::deleteAtMiddle(int key){
    node* prevNode = head; 

    // check if head node is matching node
    if(prevNode->value == key){
        deleteAtHead(); 
        return; 
    }

    bool found = false; 

    while(prevNode->next){
        if((prevNode->next)->value == key){
            found = true; 
            break; 
        }
        prevNode = prevNode->next;
    }

    if(!found) return; // Cannot find a match. So do nothing

    // After the above code there is a match 

    if(prevNode->next == tail){
        // Tail Node contains the match
        // Delete the tail Node
        deleteAtTail(); 
    }else{
        // Match is in middle of linked list 
        node* delNode = prevNode->next; 
        prevNode->next = delNode->next; 
        delNode->next = NULL; 
        delete delNode;
    }
}

void linkedList::printSLL(){
    node* curr = head; 
    while(curr){
        cout<<(curr->value)<<" -> "; 
        curr = curr->next; 
    }
    cout<<"END"<<endl; 
}

class MyHashSet : protected linkedList{
    private: 
        linkedList* llmap;
    public: 
        int tsize;  // table size

        MyHashSet(int _tsize = 10){
            tsize = _tsize; 

            llmap = new linkedList[tsize];
        }

        void add(int); 
        void remove(int); 
        bool contains(int); 

        void printLLM(); 
}; 

void MyHashSet::add(int key){
    int hashAddr = (key % tsize); 

    if(!llmap[hashAddr].contains(key)) 
        llmap[hashAddr].addAtTail(key); 
}

void MyHashSet::remove(int key){
    int hashAddr = (key % tsize); 

    if(llmap[hashAddr].contains(key)) 
        llmap[hashAddr].deleteAtMiddle(key); 
}

bool MyHashSet::contains(int key){
    return llmap[(key % tsize)].contains(key); 
}

void MyHashSet::printLLM(){
    for(int i = 0; i < tsize; i++){
        cout<<i<<": ";
        llmap[i].printSLL(); 
    }
    cout<<endl; 
}

// Testing the linked List
/* 
int main(){
    linkedList* ll1 = new linkedList(); 

    ll1->printSLL(); 

    ll1->addAtTail(1);
    ll1->addAtTail(2);
    ll1->addAtTail(3);
    ll1->addAtTail(4);
    ll1->addAtTail(5);

    ll1->printSLL(); 

    cout<<boolalpha<<(ll1->contains(1))<<endl; 
    cout<<boolalpha<<(ll1->contains(3))<<endl; 
    cout<<boolalpha<<(ll1->contains(5))<<endl; 
    cout<<boolalpha<<(ll1->contains(10))<<endl; 
    cout<<boolalpha<<(ll1->contains(100))<<endl; 

    ll1->addAtTail(6);
    ll1->addAtTail(7);
    ll1->printSLL(); 

    ll1->deleteAtMiddle(1); 
    ll1->printSLL(); 

    ll1->deleteAtMiddle(7); 
    ll1->printSLL(); 

    ll1->deleteAtMiddle(3); 
    ll1->printSLL(); 

    ll1->deleteAtMiddle(5); 
    ll1->printSLL(); 

    return 0; 
}
 */

int main(){
    MyHashSet hset1; 

    hset1.printLLM(); 

    hset1.add(1);
    hset1.add(2);

    hset1.printLLM(); 

    

    return 0; 
}