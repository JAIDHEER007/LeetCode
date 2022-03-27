// Runtime: 104ms
// Faster Than: 99.83%
// Memory Usage: 62 mb
// Less Than: 27.68%

#include<iostream>
#include<vector>
using namespace std; 

class node{
    public:
        string url; 
        node* next; 
        node* prev; 

        node(string _url){
            url = _url;  
            next = NULL; 
            prev = NULL; 
        }
};

class dll{
    private: 
        node* head;
        node* tail; 
        node* curr; 

    public:
        // dll(){
        //     head = NULL; 
        //     tail = NULL;
        //     curr = NULL; 
        // }
        dll(string homepage){
            node* startNode = new node(homepage); 
            head = startNode; 
            tail = startNode; 
            curr = startNode; 
        }

        void insertAtTail(string); 
        void deleteChain(); 

        string moveCurrB(int); 
        string moveCurrF(int); 

        void printDLL(); 
};

void dll::insertAtTail(string _url){
    node* newNode = new node(_url); 

    // Attaching the new node to tail node

    newNode->prev = tail; 
    tail->next = newNode; 

    tail = curr = newNode; 
}

void dll::deleteChain(){
    node* temp = tail;

    while(temp != curr){
        node* delNode = temp; 
        temp = temp->prev; 
        temp->next = NULL; 
        delNode->prev = NULL; 

        delete delNode; 
    }

    curr->next = NULL; 
    tail = curr; 
}

string dll::moveCurrB(int steps){
    while(curr && steps){
        curr = curr->prev; 
        --steps;
    }

    if(curr == NULL)
        curr = head; 
    return curr->url; 
}

string dll::moveCurrF(int steps){
    while(curr && steps){
        curr = curr->next; 
        --steps;
    }

    if(curr == NULL)
        curr = tail; 
    return curr->url; 
}

void dll::printDLL(){
    node* temp = head; 

    while(temp){
        cout<<(temp->url)<<" -> "; 
        temp = temp->next;
    }
    cout<<"END"<<endl; 

    temp = tail; 
    while(temp){
        cout<<(temp->url)<<" -> "; 
        temp = temp->prev; 
    }
    cout<<"END"<<endl; 

    cout<<"Current Address: "<<(curr->url)<<endl; 
}

class BrowserHistory {
    private:
        dll* internalDLL; 
    public:
        BrowserHistory(string homepage) {
            internalDLL = new  dll(homepage); 
        }
        
        void visit(string url) {
            internalDLL->deleteChain(); 
            internalDLL->insertAtTail(url); 
        }
        
        string back(int steps) {
            return internalDLL->moveCurrB(steps); 
        }
        
        string forward(int steps) {
            return internalDLL->moveCurrF(steps); 
        }
};


int main(){
    BrowserHistory bh1("leetcode.com"); 

    bh1.visit("google.com"); 
    bh1.visit("facebook.com"); 
    bh1.visit("youtube.com"); 

    cout<<bh1.back(1)<<endl; 
    cout<<bh1.back(1)<<endl; 

    cout<<bh1.forward(1)<<endl;

    bh1.visit("linkedin.com"); 

    cout<<bh1.forward(2)<<endl; 

    cout<<bh1.back(2)<<endl;
    cout<<bh1.back(7)<<endl;

    return 0; 
}