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

ListNode* removeZeroSumSublists(ListNode* head){
    unordered_map<int, ListNode*> umap; 
    ListNode* dummy = new ListNode(); 
    dummy->next = head; 

    int sum = 0; 
    umap[sum] = dummy; 
    ListNode* curr = head; 
    
    while(curr){
        // Adding the nodes value to sum
        sum += (curr->val); 

        // Checking if any node with current sum exists int the umap or not
        if(umap[sum]){
            // Found an element with same sum Lets say 'x'
            // subbaray starting from x's next to curr should be removed
            // orchestrate that operation

            ListNode* start = umap[sum]; 

            // Delete From start (exclusive) to curr (inclusive)
            
            // Store the next address from curr for later stiching
            ListNode* currNext = curr->next; 

            // temp var for deleting operation
            ListNode* temp = start->next; 

            while(temp != currNext){
                // Store the nextNode address
                ListNode* tempNext = temp->next; 

                // Add the current temp val to sum
                sum += (temp->val); 

                // Remove that sum corresponding node to NULL in umap
                umap[sum] = NULL; 

                // delete the temp node
                delete temp; 

                // Assign temp to its next address
                temp = tempNext; 
            }

            // By the logic start node will also be deleted in umap
            // But start node is neccessary so add it again
            umap[sum] = start; 

            // Attach the remaining LL to next of start
            start->next = currNext; 

            // Make the curr to start so new sum can be checked
            curr = start; 
        }else{
            // just add the sum and corresponding curr addr to umpa
            umap[sum] = curr; 
        }

        // increment the curr
        curr = curr->next; 
    }   

    ListNode* resHead = dummy->next; 
    delete dummy; 

    return resHead;  
}

int main(){
    // change the number of test cases
    int nInputs = 1;

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

        ListNode* resultHead = removeZeroSumSublists(head); 

        printSLL(resultHead); 

        // ===== END =====
    }
    
    return 0; 
}