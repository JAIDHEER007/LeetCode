#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>

using namespace std;

typedef struct ListNode{
    int value; 
    ListNode* next; 

    ListNode(int _value = 0){
        value = _value; 
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
        cout<<(curr->value)<<" "; 
        curr = curr->next; 
    }
    cout<<"END"<<endl; 
}

ListNode* swapPairs(ListNode* head){
    if(head == NULL) return NULL; 
    
    ListNode* curr1 = head; 
    ListNode* curr2 = curr1->next; 

    while(curr2 != NULL){ // Manages the Odd Length SLL 
        // Swap Operation
        swap((curr1->value), (curr2->value)); 

        // Move the pointers
        curr1 = curr2->next;
        if(curr1 == NULL) break; // Manages the even length SLL

        curr2 = curr1->next; 
    }

    return head; 
}

int main(){
    // change the number of test cases
    int nInputs = 3;

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
        // cout<<data<<endl; 

        ListNode* head = makeSLL_string(data); 

        printSLL(swapPairs(head)); 
        
        // ===== END =====
    }
    
    return 0; 
}