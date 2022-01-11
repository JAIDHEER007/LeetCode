// Runtime: 14ms
// Faster Than: 16.43%
// Memory Usage: 16.6 MB
// Less Than: 72.35%

#include<iostream>
#include<vector>

using namespace std; 

typedef struct node{
    int value; 
    node* right; 
    node* left; 
} node; 

node* getNode(int value){
    node* newNode = new node; 

    newNode->value = value; 
    newNode->left = NULL; 
    newNode->right = NULL; 

    return newNode; 
}

node* makeTree1(){
    node* n1 = getNode(1); 
    node* n2 = getNode(0); 
    node* n3 = getNode(1); 
    node* n4 = getNode(0); 
    node* n5 = getNode(1); 
    node* n6 = getNode(0); 
    node* n7 = getNode(1); 


    n1->left = n2; 
    n1->right = n3; 

    n2->left = n4; 
    n2->right = n5; 

    n3->left = n6; 
    n3->right = n7; 

    return n1; 
}

void dfs(node* root, int &sum, int tempSum = 0){
    if(root) tempSum = ((root->value) + (tempSum << 1)); 
    else return; 

    // if Current Node is a Leaf Node
    if((root->left == NULL) && (root->right == NULL)){
        cout<<tempSum<<endl; 
        sum += tempSum; 
        return; 
    }

    if(root->left) dfs(root->left, sum, tempSum);
    if(root->right) dfs(root->right, sum, tempSum);
}

int sumRootToLeaf(node* root){
    int sum = 0; 
    dfs(root, sum); 
    return sum; 
}

int main(){

    node* root = makeTree1(); 
    cout<<sumRootToLeaf(root)<<endl; 

    return 0; 
}