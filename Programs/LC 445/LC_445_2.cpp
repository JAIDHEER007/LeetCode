// Runtime: 32ms
// Faster Than: 86.78%
// Memory Usage: 75 MB
// Less Than: 6.09%

// using stack for both the input lists and the output lists
// Total Stacks used: 3
// 2 for input 
// 1 for maintaing the output

#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<stack>

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


ListNode* addTwoNumbers(ListNode* head1, ListNode* head2){
    ListNode* curr1 = head1; 
    ListNode* curr2 = head2; 

    stack<int> s1; 
    stack<int> s2; 

    while(curr1){
        s1.push(curr1->val); 
        curr1 = curr1->next; 
    }

    while(curr2){
        s2.push(curr2->val); 
        curr2 = curr2->next; 
    }

    stack<int> s3; 

    int carry = 0; 
    while(!s1.empty() || !s2.empty()){
        int x = (s1.empty())?(0):(s1.top()); 
        int y = (s2.empty())?(0):(s2.top()); 

        if(!s1.empty()) s1.pop(); 
        if(!s2.empty()) s2.pop(); 

        int sum = x + y + carry; 
        s3.push(sum % 10); 
        carry = sum / 10; 
    }
    if(carry) s3.push(carry); 

    ListNode* dummyHead = new ListNode(); 
    ListNode* curr = dummyHead; 

    while(!s3.empty()){
        ListNode* newNode = new ListNode(s3.top()); 
        curr->next = newNode; 
        curr = curr->next; 
        s3.pop(); 
    }

    ListNode* resHead = dummyHead->next; 
    dummyHead->next = NULL; 
    delete dummyHead; 

    return resHead; 
}

int main(){
    // change the number of test cases
    int nInputs = 4;

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
        string sll1; 
        getline(fin, sll1); 
    
        string sll2; 
        getline(fin, sll2); 

        ListNode* head1 = makeSLL_string(sll1); 
        ListNode* head2 = makeSLL_string(sll2); 

        printSLL(head1); 
        printSLL(head2);  
        printSLL(addTwoNumbers(head1, head2)); 
               
        // ===== END =====
    }
    
    return 0; 
}