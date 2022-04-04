// Runtime: 0ms
// Faster Than: 100.00%
// Memory Usage: 7.6mb
// Less Than: 17.64%

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

ListNode* reverseBetween(ListNode* head, int left, int right){
    ListNode* curr = head; 
    int i = 1; 

    ListNode* leftPrev = NULL; 
    ListNode* rightPtr = NULL; 
    while(curr){
        if(i == (left - 1))
            leftPrev = curr; 
        else if(i == right)
            rightPtr = curr; 
        curr = curr->next; 
        ++i; 
    }

    // if leftPrev is NULL then the left pointer is pointing to HEAD of the Linked List
    // if leftPrev is not pointing to NULL then the LeftPtr should be the next of LeftPtr
    ListNode* leftPtr = (leftPrev)?(leftPrev->next):(head); 

    // next of Right Pointer will be either NULL or Non NULL Node
    // There is no need of extra checking
    ListNode* rightNext = rightPtr->next; 

    // Reversing the middle Linked List Part
    ListNode* a = NULL; 
    ListNode* b = leftPtr; 

    while(b != rightNext){
        ListNode* c = b->next; 
        b->next = a; 

        a = b; 
        b = c; 
    }

    // Attaching the leftPtr of LL part to rightNext
	// RightNext can be either NULL or may not be NULL
	// leftPtr represent the previous head of the linked list part 
	// This will be the new tail of linked list part after reversing
	leftPtr->next = rightNext; 
	
	// Attaching the new head of the linked list part to leftPrev
	// The new head of the linkedListPart will be rightPtr
	// By making the next of leftPrev to rightPtr we are joing the reversed part to the main list
	// leftPrev can be NULL if the left is 1
	// leftPrev can be not NULL if the left is > 1
	// if leftPrev is NULL make rightPtr as head and return the head 
	// if leftPrev is not NULL then make the next of leftPrev as rightPtr
	
	if(leftPrev)
		leftPrev->next = rightPtr; 
	else 
		head = rightPtr; 
		
	return head; 	
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
        int left, right; 

        fin>>left>>right; 

        ListNode* head = makeSLL_string(data); 

        printSLL(head);   
        ListNode* newHead = reverseBetween(head, left, right); 
        printSLL(newHead); 
              
        // ===== END =====
    }
    
    return 0; 
}