// Runtime: 16ms
// Faster Than: 99.52%
// Memory Usage: 25.9MB
// Less Than: 99.76%

// This Method Works by splitting the Linked List 
// Thus Damaging the Linked List

// Time Complexity:  O(nlogn)
// Space Complexity: O(logn) 
// Single Branch in stack

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
        cout<<(curr->val)<<" "; 
        curr = curr->next; 
    }
    cout<<"END"<<endl; 
}

typedef struct TreeNode{
    int val; 
    TreeNode* left;
    TreeNode* right; 

    TreeNode(int _val = 0){
        val = _val; 
        left = NULL; 
        right = NULL; 
    }
} TreeNode; 

void preorder(TreeNode* root){
    if(root){
        cout<<(root->val)<<" "; 
        preorder(root->left); 
        preorder(root->right); 
    }
}

void inorder(TreeNode* root){
    if(root){
        inorder(root->left); 
        cout<<(root->val)<<" "; 
        inorder(root->right); 
    }
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

void dfs(ListNode* head, TreeNode* root, bool isRight = false){
    if(root){
        // Finding the midPrev
        ListNode* midPrev = getMidPrev(head); 
        
        if(midPrev){
            // if midPrev is NULL then the Linked List is empty 
            // We can stop and take it as our base case

            ListNode* mid = midPrev->next; 
            ListNode* p1Head; 
            ListNode* p2Head;  

            if(mid){
                midPrev->next = NULL; 
                p1Head = head; 
                p2Head = mid->next; 
                mid->next = NULL;
            }else{
                mid = midPrev; 
                p1Head = p2Head = NULL; 
            }

            TreeNode* newRoot = new TreeNode(mid->val); 

            if(isRight)
                root->right = newRoot; 
            else
                root->left = newRoot;

            dfs(p1Head, newRoot, false); // Left Sub Tree
            dfs(p2Head, newRoot, true); // Right Sub Tree
        }
    }
}

TreeNode* sortedListToBST(ListNode* head) { 
    TreeNode* dummyRoot = new TreeNode(); 

    dfs(head, dummyRoot, false); 

    TreeNode* realRoot = dummyRoot->left; 
    dummyRoot->left = NULL; 

    delete dummyRoot; 
    return realRoot; 
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
        TreeNode* root = sortedListToBST(head); 

        inorder(root);  cout<<endl; 
        preorder(root); cout<<endl; 
        
        // ===== END =====
    }
    
    return 0; 
}