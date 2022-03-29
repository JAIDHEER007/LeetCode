#include<iostream>
#include<vector>

using namespace std; 

typedef struct TreeNode
{
    int val; 
    TreeNode* right; 
    TreeNode* left; 

    TreeNode(int _val = 0){
        val = _val; 
        right = NULL; 
        left = NULL; 
    }
} TreeNode;

void printLL(TreeNode* head){
    TreeNode* curr = head; 

    while(curr){
        cout<<(curr->val)<<" -> "; 
        curr = curr->right; 
    }
    cout<<"END"<<endl; 
}

TreeNode* makeTree1(){
    TreeNode* n1 = new TreeNode(1); 
    TreeNode* n2 = new TreeNode(2); 
    TreeNode* n3 = new TreeNode(3); 
    TreeNode* n4 = new TreeNode(4); 
    TreeNode* n5 = new TreeNode(5);

    n1->left = n2; 
    n1->right = n3; 

    n2->left = n4; 
    n2->right = n5; 

    return n1;  
}

TreeNode* dfs(TreeNode* root){
    if(root == NULL) return NULL; 
    if((root->left == NULL) && (root->right == NULL)){
        // Leaf Node
        return root; 
    }

    TreeNode* leftTail = dfs(root->left); 
    TreeNode* rightTail = dfs(root->right); 

    if(leftTail == NULL){
        // Left Tail is NULL
        // There is no need of stiching of left subtree to right as there is no 
        // Left Subtree
        // Right subtree may or maynot be present 
        // Just return the righTail
        return rightTail; 
    }

    TreeNode* leftTemp = root->left; 
    TreeNode* rightTemp = root->right; 

    root->left = NULL; // Remove the connection to left subtree

    root->right = leftTemp; // Attach the left subtree to right ptr of root

    leftTail->right = rightTail; // Attach the right subtree to the attached flattened left subtree

    return (rightTail)?(rightTail):(leftTail); // If right tail is not NULL return it or else return the left tail 
}

void flatten(TreeNode* root){
    TreeNode* dummy = dfs(root); 
}

int main(){

    TreeNode* root = makeTree1(); 
    
    flatten(root); 

    printLL(root); 


    return 0; 
}