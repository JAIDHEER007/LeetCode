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

ListNode* mergeNodes(ListNode* head){
    ListNode* dummyHead = new ListNode(); 
    ListNode* curr = head; 
    ListNode* curr1 = dummyHead; 

    int sum = 0; 
    while(curr){
        if(curr->val == 0){
            // As the first Node is zero 
            // This will be triggred at the first node
            // In that case we should not add a node to the result linked list 
            
            if(curr != head){
                // This will rule out the possibility of 
                // Adding a node to result linked list at the starting node
                ListNode* newNode = new ListNode(sum); 
                sum = 0; 
                curr1->next = newNode;
                curr1 = curr1->next; 
            }
        }else
            sum += (curr->val); 
        curr = curr->next; 
    }

    // Remove the dummyHead; 
    ListNode* resultHead = dummyHead->next; 

    delete dummyHead;
    return resultHead; 
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
        
        printSLL(head);    
        printSLL(mergeNodes(head));      
        // ===== END =====
    }
    
    return 0; 
}