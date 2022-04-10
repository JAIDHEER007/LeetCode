#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>

using namespace std;

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

TreeNode* sortedArrayToBST(vector<int>& nums) {
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
        int n; fin>>n; 

        vector<int> nums(n); 
        for(int i = 0; i < n; ++i)
            fin>>nums[i]; 
        
        TreeNode* root = sortedArrayToBST(nums); 
        
        inorder(root);  cout<<endl; 
        preorder(root); cout<<endl;

        // ===== END =====
    }
    
    return 0; 
}