// Runtime: 262ms
// Faster than: 76.88%
// Memory Usage: 117.3mb
// Less Than: 51.33%

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

vector<int> nodesBetweenCriticalPoints(ListNode* head){
    ListNode* a = head; 
    if(a == NULL)
        return {-1, -1}; 
    
    ListNode* b = a->next; 
    if(b == NULL)
        return {-1, -1}; 

    ListNode* c = b->next; 
    int i = 1; 
    vector<int> ciriticalPoints; 

    while(c){
        int aVal = (a->val); 
        int bVal = (b->val); 
        int cVal = (c->val); 

        if(((aVal > bVal) && (cVal > bVal)) || ((aVal < bVal) && (cVal < bVal)))
            ciriticalPoints.push_back(i); 
        
        a = b; 
        b = a->next; 
        c = b->next; 
        ++i; 
    }

    int cpSize = ciriticalPoints.size(); 
    if(cpSize < 2) return {-1, -1}; 

    int maxDst = INT_MIN; 
    int minDst = INT_MAX; 

    for(int i = 1; i < cpSize; ++i){
        maxDst = max(maxDst, (ciriticalPoints[i] - ciriticalPoints[0])); 
        minDst = min(minDst, (ciriticalPoints[i] - ciriticalPoints[i - 1])); 
    }

    return {minDst, maxDst}; 
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

        printSLL(head); 
        vector<int> dsts = nodesBetweenCriticalPoints(head); 

        cout<<dsts[0]<<"  "<<dsts[1]<<endl; 

        // ===== END =====
    }
    
    return 0; 
}