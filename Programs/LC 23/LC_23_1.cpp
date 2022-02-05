// Used HashMap 

// Runtime: 34ms
// Faster than: 54.18%
// Memory Usage: 14.5 mb
// Less Than: 7.89%

// k: number of Lists
// n: Average Number of nodes in each list

// Possible Time Complexity: O(kn + nlogn)
// Possible Space COmplexity: O(kn) all elements are distinct

#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<map>
  
using namespace std;

typedef struct ListNode{
    int value; 
    ListNode *next; 

    ListNode(int _value = 0){
        this->value = _value; 
        this->next = NULL; 
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

vector<ListNode*> makeSLL_count(int _value, int count){
    if(count == 0) return {NULL, NULL}; 

    ListNode* head = new ListNode; 
    ListNode* tail = NULL; 
    ListNode* curr = head; 
    for(int i = 0; i < count; i++){
        tail = new ListNode(_value); 
        curr->next = tail; 
        curr = curr->next;  
    }

    return {head->next, tail}; 
}

ListNode* mergeKLists(vector<ListNode*> lists){
    map<int, int> hmap; 

    int k = lists.size(); 
    for(int i = 0; i < k; i++){
        ListNode* curr = lists[i]; 
        while(curr){
            ++hmap[curr->value]; 
            curr = curr->next; 
        }
    }

    ListNode* head = new ListNode; 
    ListNode* curr = head; 

    for(map<int, int>::iterator itr = hmap.begin(); itr != hmap.end(); ++itr){
        vector<ListNode*> ptrs = makeSLL_count((itr->first), (itr->second)); 

        curr->next = ptrs[0]; 
        curr = ptrs[1]; 
    }

    return head->next; 
}

void printSLL(ListNode* head){
    ListNode* curr = head; 

    while(curr){
        cout<<(curr->value)<<" -> "; 
        curr = curr->next; 
    }

    cout<<"END"<<endl; 
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
        
        int k; fin>>k; 

        fin.ignore(1, '\n'); // Ignore the newline character So getline work correctly

        vector<ListNode*> lists(k); 
        for(int i = 0; i < k; i++){
            string input;
            getline(fin, input); 

            lists[i] = makeSLL_string(input);  
        }

        ListNode* resultHead = mergeKLists(lists); 

        printSLL(resultHead); 
        
        // ===== END =====
    }
    
    return 0; 
}