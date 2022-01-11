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

int dfs(node* root, int tempSum = 0){
    if(root == NULL)
        return 0; 
    tempSum = ((root->value) + (tempSum << 1));
    if((root->left == NULL) && (root->right == NULL))
        return tempSum; 
    return dfs(root->left, tempSum) + dfs(root->right, tempSum); 
}

int sumRootToLeaf(node* root){
    return dfs(root, 0); 
}
int main(){

    node* root = makeTree1(); 
    cout<<sumRootToLeaf(root)<<endl; 

    return 0; 
}