// Moves the node from orignal Linked List to new Linked List 
// No new nodes will be created

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

ListNode* partition(ListNode* head, int x) {
    ListNode* head1 = new ListNode(); 
    ListNode* curr1 = head1; 

    ListNode* head2 = new ListNode(); 
    ListNode* curr2 = head2; 

    ListNode* curr3 = head; 

    while(curr3){
        if((curr3->val) < x){
            curr1->next = curr3;  
            curr1 = curr1->next; 
        }else{
            curr2->next = curr3;
            curr2 = curr2->next; 
        }

        ListNode* nextNode = curr3->next; 
        curr3->next = NULL; 
        curr3 = nextNode; 
    }       

    curr1->next = head2->next; 
    head2->next = NULL; 

    ListNode* realHead = head1->next; 
    head1->next = NULL; 

    delete head1; 
    delete head2; 

    return realHead; 
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
        string data; getline(fin, data); 

        ListNode* head = makeSLL_string(data); 

        int x; fin>>x; 

        ListNode* resHead = partition(head, x); 

        printSLL(resHead); 
        
        // ===== END =====
    }
    
    return 0; 
}