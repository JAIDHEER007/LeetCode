// 165 / 165 Cases done but Took Too Long TLE
// Used NFS

// Runtime: 956ms
// Faster Than: 97.73%
// Memory Usage: 327.9mb
// Less Than: 89.41%

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

void reverse(ListNode* head, ListNode* end){
    ListNode* a = NULL; 
    ListNode* b = head; 
    ListNode* c = NULL;

    while(b != end){
        c = b->next; 
        b->next = a; 

        a = b; 
        b = c; 
    }
}

ListNode* reverseEvenLengthGroups(ListNode* head){
    ListNode* A = NULL; 
    ListNode* B = head; 
    ListNode* C = head; 
    ListNode* D = head->next; 

    int gLen = 1; 
    while(D){
        int i = 1; 
        while(C && C->next && (i < gLen)){
            C = C->next; 
            ++i; 
        }

        int grpSize = i; 
        D = ((C)?(C->next):(NULL)); 
        if((grpSize % 2) == 0){
            // cout<<"Got here"<<endl;
            reverse(B, D); 
            A->next = C; 
            B->next = D;

            A = B;  
        }else       
            A = C;

        B = C = D; 

        // Increase the gLen by one
        ++gLen; 

    }

    return head; 
}

int main(){
    // change the number of test cases
    int nInputs = 6;

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

        ListNode* head = makeSLL_string(data); 

        printSLL(reverseEvenLengthGroups(head)); 

        // ===== END =====
    }
    
    return 0; 
}