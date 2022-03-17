// m: length of Linked List 1
// n: length of linked list 2

// Time Complexity: O(m) + O(n)
// Space Complexity: O(m)

#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<unordered_map>

using namespace std;

typedef struct ListNode{
    int val; 
    ListNode* next; 

    ListNode(int _val = 0){
        val = _val; 
        next = NULL; 
    }
} ListNode; 

void join(ListNode* head1, ListNode* head2, ListNode* head3){
    ListNode* tail1 = head1; 
    if(tail1){
        while(tail1->next)
            tail1 = tail1->next; 
        tail1->next = head3; 
    }
    ListNode* tail2 = head2; 
    if(tail2){
        while(tail2->next)
            tail2 = tail2->next; 
        tail2->next = head3; 
    }
}

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

ListNode* getIntersectionNode(ListNode* head1, ListNode* head2){
    unordered_map<ListNode*, bool> umap; 

    ListNode* curr1 = head1; 
    while(curr1){
        umap[curr1] = true; 
        curr1 = curr1->next; 
    }

    ListNode* curr2 = head2; 
    while(curr2){
        if(umap[curr2]) return curr2; 
        curr2 = curr2->next; 
    }

    return NULL; 
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
        string data1; getline(fin, data1); 
        string data2; getline(fin, data2); 
        string data3; getline(fin, data3); 

        ListNode* head1 = makeSLL_string(data1); 
        ListNode* head2 = makeSLL_string(data2); 
        ListNode* head3 = makeSLL_string(data3);

        // printSLL(head1); 
        // printSLL(head2); 
        // printSLL(head3);  

        join(head1, head2, head3); 

        // printSLL(head1); 
        // printSLL(head2); 
        // printSLL(head3);  

        ListNode* intersectNode = getIntersectionNode(head1, head2); 

        if(intersectNode == NULL)
            cout<<"No Intersection"<<endl; 
        else
            cout<<"Intersecting at "<<(intersectNode->val)<<endl; 
        // ===== END =====
    }
    
    return 0; 
}