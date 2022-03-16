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

ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
    ListNode* curr1 = head1; 
    ListNode* curr2 = head2; 

    // DummyHead
    ListNode* dummyHead = new ListNode(); 
    ListNode* curr = dummyHead; 

    while(curr1 &&  curr2){
        int comprValue = 0; // Comaprision Result 
        if((curr1->val) < (curr2->val)){
            comprValue = (curr1->val); 
            curr1 = curr1->next; 
        }else{
            comprValue = (curr2->val); 
            curr2 = curr2->next; 
        }

        ListNode* newNode = new ListNode(comprValue); 

        curr->next = newNode; 
        curr = curr->next; 
    }

    while(curr1){
        curr->next = new ListNode(curr1->val); 
        curr1 = curr1->next; 
        curr = curr->next; 
    }

    while(curr2){
        curr->next = new ListNode(curr2->val); 
        curr2 = curr2->next; 
        curr = curr->next; 
    }

    // Remove the dummy head
    ListNode* resultHead = dummyHead->next; 
    dummyHead->next = NULL; 
    delete dummyHead; 

    return resultHead; 
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
        string data1; getline(fin, data1); 
        string data2; getline(fin, data2); 

        ListNode* head1 = makeSLL_string(data1);
        ListNode* head2 = makeSLL_string(data2);        

        printSLL(head1); 
        printSLL(head2); 

        ListNode* head3 = mergeTwoLists(head1, head2); 

        printSLL(head3); 

        // ===== END =====
    }
    
    return 0; 
}