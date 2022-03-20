// Runtime: 215 ms
// Faster Than: 86.09 %
// Memory Usage: 110.3 mb
// Less than: 98.20%

// Time Complexity: O(n)
// Space Complexiy: O(1)

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

bool isPalindrome(ListNode* head){
    ListNode* a = NULL; 
    ListNode* b = head;     // Slow Moving Pointer
    ListNode* fast = head;  // Fast Moving Pointer

    while(fast && fast->next){
        // Move the fast pointer by 2 steps
        fast = fast->next->next; 

        // Reverse the Linked List 
        ListNode* c = b->next; 
        b->next = a; 

        a = b; 
        b = c; 
    }

    ListNode* head1 = a;
    ListNode* head2 = b;  

    // Check if fast is null or fast.next is null
    // if fast is null then lenght of linked list is even ==> exact division 
    // if fast is not null. then fast.next is null then length of linked list is odd ==> uneven division 
    // Node division skipping should happen; 

    if(fast) head2 = head2->next; // Middle node skipped

    // Check for palindrome
    while(head1 && head2){
        if((head1->val) != (head2->val)) return false; 
        head1 = head1->next; 
        head2 = head2->next; 
    } 

    return true; 
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

        printSLL(head);

        cout<<boolalpha<<isPalindrome(head)<<endl;          
        // ===== END =====
    }
    
    return 0; 
}