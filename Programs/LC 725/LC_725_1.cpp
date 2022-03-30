// Runtime: 7ms
// Faster Than: 82.83%
// Memory Usage: 8.9MB
// Less Than: 86.59%


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

vector<ListNode*> splitListToParts(ListNode* head, int k){
    int N = 0; // Length of the Linked List

    ListNode* curr = head;  
    while(curr){
        ++N; 
        curr = curr->next; 
    }
    
    int x = N / k;  // Number of elements in each part
    int y = N % k;  // Number of extra elements that needed to be added for first few parts

    vector<ListNode*> result; 
    curr = head; 

    if(x){
        for(int i = 0; i < k; i++){
            result.push_back(curr); 
            for(int j = 1; j < x + ((y > 0)?(1):(0)); j++){
                curr = curr->next; 
            }

            if(y > 0) --y; 
            ListNode* temp = curr->next;
            curr->next = NULL; 
            curr = temp; 
        }
    }else{
        for(int i = 0; i < k; ++i){
            result.push_back(curr); 
            if(curr){
                ListNode* temp = curr->next; 
                curr->next = NULL; 
                curr = temp; 
            }
        }
    }
    
    return result; 
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
        string data; getline(fin, data); 
        int k; fin>>k; 

        ListNode* head = makeSLL_string(data); 

        vector<ListNode*> result = splitListToParts(head, k); 

        for(int i = 0; i < k; ++i){
            printSLL(result[i]); 
        }

        // ===== END =====
    }
    
    return 0; 
}