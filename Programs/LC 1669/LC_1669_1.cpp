#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>

using namespace std;

typedef struct ListNode{
    int val; 
    ListNode* next; 

    ListNode(int _val = 0){
        val = _val; 
        next = NULL; 
    }
} ListNode; 


ListNode* makeSLL_string(string input){
    if(input.length() == 0) return NULL; 

    string token; 
    ListNode* head = new ListNode;  // Dummy Head 
    stringstream ss(input); 

    ListNode* curr = head; 
    while(ss >> token){
        ListNode* newNode = new ListNode(stoi(token)); 

        curr->next = newNode; 
        curr = curr->next; 
    }

    if(head->next == NULL) return NULL; 
    return head->next; 
}

void printSLL(ListNode* head){
    ListNode* curr = head; 
    while(curr){
        cout<<(curr->val)<<" -> "; 
        curr = curr->next; 
    }
    cout<<"END"<<endl; 
}

ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2){
    // finding the (a - 1) and b node in list1
    
    ListNode* curr = list1; 
    int i = 0; 
    ListNode* aPrevNode = NULL; 
    ListNode* bNode = NULL; 

    while(curr){
        if(i == (a - 1))
            aPrevNode = curr; 
        if(i == b)
            bNode = curr; 
        curr = curr->next; 
        ++i; 
    }

    // Attaching the Second Linked List

    // a'th Node 
    ListNode* delStartNode = aPrevNode->next; 

    // Attaching the head of second Linked List to previous Node of a
    aPrevNode->next = list2; 

    // Getting to the tail node of second Linked List
    ListNode* tail2 = list2; 
    while(tail2->next)
        tail2 = tail2->next; 
    
    // Attaching the tail pointer of second linked list to NextNode of b
    tail2->next = bNode->next; 

    // Making the bNode next to NULL and removing the conection with first Linked List
    bNode->next = NULL; 

    // Now the Linked Lists are attached
    
    // Delete the removed part of first Linked List to free the memory 
    curr = delStartNode; 
    while(curr){
        ListNode* delNode = curr; 
        curr = curr->next; 

        delete delNode; 
    }
    
    // Return the head of List1
    return list1; 
}

int main(){
    // change the number of test cases
    int nInputs = 2;

    // test case files should be input1.txt, input2.txt, ..., inputN.txt format
    for(int i = 1; i <= nInputs; i++){
        string filename = "input" + to_string(i) + ".txt"; 

        ifstream fin(filename); 
        if(!fin.is_open()){
            cout<<"Cannot Open the test case"<<endl;
            return 0; 
        }

        cout<<"======== TestCase "<<i<<" ========"<<endl;


        // Write input and output here
        // Instead of cin use fin

        // ===== START =====
        string ll1, ll2; 
        getline(fin, ll1); 
        getline(fin, ll2); 

        ListNode* list1 = makeSLL_string(ll1); 
        ListNode* list2 = makeSLL_string(ll2); 

        
        int a; fin>>a; 
        int b; fin>>b; 

        printSLL(list1); 
        printSLL(list2); 

        printSLL(mergeInBetween(list1, a, b, list2)); 

        // ===== END =====
    }
    
    return 0; 
}