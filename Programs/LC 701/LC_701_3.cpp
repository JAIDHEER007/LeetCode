#include<iostream>
#include<sstream>
#include<queue>
using namespace std; 

typedef struct node{
    int value; 
    node* left; 
    node* right; 
} node; 

node* getNode(int value = 0){
    node* newNode = new node; 
    newNode->value = value;
    newNode->left = NULL; 
    newNode->right = NULL; 

    return newNode;  
}

void inorder(node* root){
    if(root){
        inorder(root->left); 
        cout<<root->value<<" "; 
        inorder(root->right); 
    }
}

void levelOrder(node* root){
    if(root == NULL){
        cout<<"Empty Tree"<<endl; 
        return; 
    }
    
    queue<node*> q; 
    q.push(root); 

    while(!q.empty()){
        node* currNode = q.front();
        q.pop();  

        cout<<(currNode->value)<<" "; 

        if(currNode->left) q.push(currNode->left);
        if(currNode->right) q.push(currNode->right);
    }
    cout<<endl; 
}

node* makeTree_ps(string pstring){
    stringstream ss(pstring); 
    string token; 

    int level = 0;  
    node* root = NULL; 

    queue<node*> q; 
    int count = 0; 

    bool left = true; 
    while(ss >> token){
        if(level == 0){
            if(token != "NULL"){
                root = getNode(stoi(token)); 
                q.push(root); 
                ++level; 
            }else return root; 
        }else{
            node* currNode = q.front(); 
            if(token != "NULL"){
                node* newNode = getNode(stoi(token)); 
                if(left) currNode->left = newNode; 
                else currNode->right = newNode; 
                q.push(newNode); 
            }else
                q.push(NULL);
            ++count; 
            if(count % 2 == 0) q.pop(); 
            if(count == (1 << level)){
                ++level;
                count = 0; 
            }
            left = !left; 
        }
    }

    return root; 
}

node* insertIntoBST(node* root, int val){
    // Base case
    // Empty Tree
    if(root == NULL){
        return getNode(val);
    }else{
        if(val > (root->value))
            root->right = insertIntoBST(root->right, val);
        else
            root->left = insertIntoBST(root->left, val);
    }

    return root; 
}

int main(){
    // string pstring = "4 2 7 1 3 NULL NULL"; 
    // string pstring = "1 2 3 4 5 6 7 8 9 10 NULL NULL NULL NULL NULL"; 
    // string pstring = "1 2 NULL 3 NULL NULL NULL 4 NULL NULL NULL NULL NULL NULL NULL"; 
    string pstring = "40 20 60 10 30 50 70"; 


    node* root = makeTree_ps(pstring); 

    levelOrder(root); 

    root = insertIntoBST(root, 25); 

    levelOrder(root); 

    return 0; 
}