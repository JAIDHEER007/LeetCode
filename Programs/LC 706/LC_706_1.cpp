#include<iostream>
#include<vector>

using namespace std; 

class node{
    public:
        int key; 
        int value; 
        node* next; 

        node(){
            key = 0; 
            value = 0; 
            next = NULL; 
        }
        node(int k, int v){
            key = k; 
            value = v; 
            next = NULL; 
        }
        node(int k, int v, node* nextptr){
            key = k; 
            value = v; 
            next = nextptr; 
        }
}; 

class linkedList : protected node{
    private: 
        node* head; 
        node* tail; 

        void deleteAtHead(); 
        void deleteAtTail();
        node* contains(int); 

    public: 
        linkedList(){
            head = NULL; 
            tail = NULL; 
        }

        int getKV(int); 

        void addNode(int, int);
        void deleteNode(int);
        
        void printSLL(void); 
};

int linkedList::getKV(int key){
    node* addr = contains(key); 

    return ((addr)?(addr->value):(-1)); 
}

node* linkedList::contains(int key){
    node* curr = head; 
    while(curr){
        if(curr->key == key) return curr; 
        curr = curr->next; 
    }

    return NULL; 
}

void linkedList::addNode(int key, int value){
    // Check if the node exists in the linked list
    node* addr = contains(key); 

    if(addr != NULL){
        // Node already exists in the linked list 
        // Update the node with new value
        addr->value = value; 

        return; 
    }

    // From this point Node doesn't exist in the linked list 
    // Add the node to the linked list

    node* newNode = new node(key, value);
    if((head == tail) && (tail == NULL)){ 
        // Linked List is empty
        head = tail = newNode;            
        return; 
    }

    tail->next = newNode; 
    tail = newNode; 
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

void linkedList::deleteNode(int key){
    // if linked list is empty 
    // Do nothing
    if((head == tail) && (head == NULL))
        return; 

    node* prevNode = head; 

    // check if head node is matching node
    if(prevNode->key == key){
        deleteAtHead(); 
        return; 
    }

    bool found = false; 

    while(prevNode->next){
        if((prevNode->next)->key == key){
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
        cout<<"["<<(curr->key)<<", "<<(curr->value)<<"]"<<" -> "; 
        curr = curr->next; 
    }
    cout<<"END"<<endl; 
}

class MyHashMap : protected linkedList{
    private: 
        linkedList* llmap;
    public: 
        int tsize;  // table size

        MyHashMap(int _tsize = 10){ // Use a Prime Number like 499 for best performance
            tsize = _tsize; 

            llmap = new linkedList[tsize];
        }

        void put(int, int); 
        int get(int); 
        void remove(int); 

        void printLLM(); 
}; 

void MyHashMap::put(int key, int value){
    int hashAddr = (key % tsize); 

    llmap[hashAddr].addNode(key, value); 
}

int MyHashMap::get(int key){
    int hashAddr = (key % tsize); 

    return llmap[hashAddr].getKV(key); 
}

void MyHashMap::remove(int key){
    int hashAddr = (key % tsize); 

    llmap[hashAddr].deleteNode(key); 
}

void MyHashMap::printLLM(){
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
    MyHashMap hmap1; 

    // hmap1.printLLM(); 

    hmap1.put(1, 1); 
    hmap1.put(2, 2); 

    hmap1.printLLM(); 

    cout<<hmap1.get(1)<<endl; 
    cout<<hmap1.get(3)<<endl; 

    hmap1.put(2, 1); 

    hmap1.printLLM(); 

    cout<<hmap1.get(2)<<endl; 

    hmap1.remove(2); 

    cout<<hmap1.get(2)<<endl; 

    hmap1.printLLM(); 
    
    return 0; 
}