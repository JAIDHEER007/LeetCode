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

void deleteNode(ListNode* node){
    ListNode* nextNode = node->next; 
    node->val = nextNode->val; 

    node->next = nextNode->next; 
    nextNode->next = NULL; 

    delete nextNode; 
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
        string data; 
        getline(fin, data); 
        
        int del; 
        fin>>del; 

        ListNode* head = makeSLL_string(data); 
        printSLL(head); 

        ListNode* node = head; 

        while(node){
            if(node->val == del) break; 
            node = node->next; 
        }

        deleteNode(node); 

        printSLL(head); 
        // ===== END =====
    }
    
    return 0; 
}