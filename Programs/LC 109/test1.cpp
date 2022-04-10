#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>

// Splitting the Linked List at MID

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

ListNode* getMidPrev(ListNode* head){
    ListNode* slow = head; 
    ListNode* fast = head; 
    ListNode* prev = head; 

    while(fast && fast->next){
        if(slow != head)
            prev = prev->next; 
        
        slow = slow->next; 
        fast = fast->next->next; 
    }

    return prev; 
}

int main(){
    // change the number of test cases
    int nInputs = 7;

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
        printSLL(head);


        ListNode* midPrev = getMidPrev(head); 
        if(midPrev){
            ListNode* mid = midPrev->next; 

            ListNode* p1Head; 
            ListNode* p2Head;  

            if(mid){
                // Mid is present

                // Remove the Connection b/w midPrev and mid
                midPrev->next = NULL; 

                // p1Head will be the start of LL
                p1Head = head; 

                // p2Head will be the next node of mid
                p2Head = mid->next; 

                // Remove the connection b/w mid and p2Head
                mid->next = NULL;
            }else{
                // If mid i.e, midPrev->next is NULL
                // Then LL contains only one element and that single element is the mid
                mid = midPrev; 
                
                // If the mid is removed then both the heads 
                // will become NULL
                p1Head = p2Head = NULL; 
            }

            cout<<"Mid Value: "<<(mid->val)<<endl; 
            printSLL(p1Head); 
            printSLL(p2Head); 
        }else
            cout<<"Linked List is Empty"<<endl; 

        // ===== END =====
    }
    
    return 0; 
}