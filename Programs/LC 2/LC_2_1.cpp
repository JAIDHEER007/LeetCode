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

ListNode* addTwoNumbers(ListNode* head1, ListNode* head2){
    int carry = 0; 
    int sum = 0; 

    ListNode* dummyHead = new ListNode(); 
    ListNode* curr = dummyHead; 

    ListNode* l1 = head1; 
    ListNode* l2 = head2; 

    while(l1 && l2){
        int sum = (l1->val) + (l2->val) + carry; 

        carry = sum / 10; 

        curr->next = new ListNode(sum % 10); 
        curr = curr->next; 

        l1 = l1->next; 
        l2 = l2->next; 
    }

    ListNode* rNode = (l1)?(l1):(l2); 
    while(rNode){
        int sum = (rNode->val) + carry; 

        carry = sum / 10; 

        curr->next = new ListNode(sum % 10); 
        curr = curr->next; 
        rNode = rNode->next; 
    }

    if(carry)
        curr->next = new ListNode(carry); 
    
    ListNode* realHead = dummyHead->next; 
    dummyHead->next = NULL; 

    delete dummyHead; 

    return realHead; 
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