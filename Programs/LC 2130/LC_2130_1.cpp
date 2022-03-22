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

int pairSum(ListNode* head){
    ListNode* a = NULL; 
    ListNode* b = head; 
    ListNode* fast = head; 

    // Break the Linked List into 2 halves
    // Parallely Reverse the firt half


    while(fast && fast->next){
        // Move the fast pointer by 2 nodes
        fast = fast->next->next; 

        // Reverse the Linked List
        
        // Strore the Next Address
        ListNode* c = b->next; 

        // Reverse the Link
        b->next = a;

        // Move Forward
        a = b; 
        b = c; 
    }

    ListNode* head1 = a; // Head of First Half
    ListNode* head2 = b; // Head of Second Half

    // Check for the max Twin sum

    int twinSum = 0;

    while(head1 && head2){
        twinSum = max(twinSum, ((head1->val) + (head2->val))); 
        head1 = head1->next; 
        head2 = head2->next;
    }

    return twinSum; 
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
        string data; 
        getline(fin, data); 

        ListNode* head = makeSLL_string(data); 

        cout<<pairSum(head)<<endl;         
        // ===== END =====
    }
    
    return 0; 
}