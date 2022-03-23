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

ListNode* swapNodes(ListNode* head, int k) {
    ListNode* curr = head; 
    ListNode* k1 = NULL; 

    int i = 0;
    int len = 0;  
    while(curr){
        if(i == k - 1)
            k1 = curr; 
        curr = curr->next; 
        ++i;
        ++len; 
    }

    curr = head; 
    i = 0; 
    ListNode* k2 = NULL;
    while(curr){
        if(i == (len - k)){
            k2 = curr; 
        }
        curr = curr->next; 
        ++i; 
    }

    // Swapp the nodes
    swap(k1->val, k2->val); 

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

        ListNode* head = makeSLL_string(data); 
        int k; fin>>k; 

        printSLL(swapNodes(head, k)); 
        // ===== END =====
    }
    
    return 0; 
}