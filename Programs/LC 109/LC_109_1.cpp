// Runtime: 32ms
// Faster Than: 66.69%
// Memory Usage: 26.1MB
// Less Than: 98.56%

// Time Complexity:  O(n)
// Space Complexity: O(n) 

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

void dfs(vector<int> &nums, int low, int high, 
        TreeNode* root, bool isRight = false){
    if(root){
        if(high >= low){
            int mid = low + (high - low) / 2; 
            TreeNode* newRoot = new TreeNode(nums[mid]); 

            if(isRight)
                root->right = newRoot; 
            else
                root->left = newRoot;

            dfs(nums, low, mid - 1, newRoot, false); // Left Sub Tree
            dfs(nums, mid + 1, high, newRoot, true); // Right Sub Tree
        }
    }
}

TreeNode* sortedListToBST(ListNode* head) { 
    vector<int> nums; 

    ListNode* curr = head; 
    while(curr){
        nums.push_back(curr->val); 
        curr = curr->next; 
    }       

    TreeNode* dummyRoot = new TreeNode(); 
    int low = 0; 
    int high = nums.size() - 1; 

    dfs(nums, low, high, dummyRoot, false); 

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