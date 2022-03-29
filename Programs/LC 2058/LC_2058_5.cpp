// Without maintaing a count variable

// Runtime: 156ms
// Faster than: 99.76%
// Memory Usage: 113.2 MB
// Less Than: 99.39%

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

    int firstCp = -1;   // First Critical Point. Should be stored for finding the max distance
    int prevCp = -1;    // Previous Critical Point. Should be stored for finding the min distance

    int maxDst = INT_MIN; 
    int minDst = INT_MAX; 

    while(c){
        int aVal = (a->val); 
        int bVal = (b->val); 
        int cVal = (c->val); 

        if(((aVal > bVal) && (cVal > bVal)) || ((aVal < bVal) && (cVal < bVal))){
            // Found a Critical Point

            if(firstCp == -1){
                // First Critical Point not yet found
                // Make this cp as FirstCp
                firstCp = i; 
            }else{
                // First CP was found
                // New CP was also Found
                // So there are 2 CP's

                maxDst = max(maxDst, (i - firstCp)); 
                minDst = min(minDst, (i - prevCp)); 
            }
            
            // Make this CP as previous CP 
            // So we can compre the new CP's
            prevCp = i; 

        }
        
        a = b; 
        b = a->next; 
        c = b->next; 
        ++i; 
    }

    // if firstCP is -1 means there are no CP's
    // if firstCP is same as prevCP then there is only 1 CP that is firstCP
    // In this case return {-1, -1}

    if(firstCp == -1 || (firstCp == prevCp)) return {-1, -1}; 
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