// Runtime: 12ms
// Faster Than: 94.52%
// Memory Usage: 11.5MB
// Less Than: 75.57%

// O(1) extra space

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

void reverse(ListNode* start, ListNode* end){
    ListNode* a = NULL; 
    ListNode* b = start; 
    ListNode* c = NULL; 

    while(b != end){
        c = b->next; 
        b->next = a; 

        a = b;
        b = c; 
    }
}

ListNode* reverseKGroup(ListNode* head, int k){

    // ptr A, B are to maintian the segment start and end    
    ListNode* A = head; 
    ListNode* B = head; 

    // used to maintain the tail of previous segment
    ListNode* C = NULL; 

    // bool firstPart = false; 
    ListNode* newHead = NULL; 

    while(B){
        int i = k; 

        while(B && B->next && i != 1){
            B = B->next; 
            --i; 
        }

        ListNode* D = B->next; 
        if(i == 1){
            // Complete segment found
            // Reverse the part 

            // Save the head
            if(C == NULL)
                newHead = B; 

            // Reverse the segment
            reverse(A, D); 

            A->next = D; 
            if(C) C->next = B; 
        }
        C = A; 
        A = D; 
        B = A; 
    }

    return newHead; 
}

int main(){
    // change the number of test cases
    int nInputs = 5;

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
        string data; getline(fin, data); 
        ListNode* head = makeSLL_string("1 2 3 4"); 

        printSLL(head); 
        int k; fin>>k;
        cout<<"K: "<<k<<endl;

        ListNode* newHead = reverseKGroup(head, k); 

        printSLL(newHead); 

        // ===== END =====
    }
    
    return 0; 
}