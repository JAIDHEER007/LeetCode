// Runtime: 96 ms
// Faster Than: 44.87%
// Memory Usage: 57 MB
// Less Than: 49.52%

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

void insert(node* root, int val){
    if(val > (root->value)){
        // will be inserted in right subtree
        if(root->right){
            // If root->right is not NULL i.e, as a right child
            insert(root->right, val);
        }else{
            // There is no right child
            // Simply insert
            root->right = getNode(val); 
        } 
    }else{
        // will be inserted in left subtree
        if(root->left){
            // If root->left is not NULL i.e, as a right child
            insert(root->left, val);
        }else{
            // There is no left child
            // Simply insert
            root->left = getNode(val); 
        }
    }
}

node* insertIntoBST(node* root, int val){
    // Base case
    // Empty Tree
    if(root == NULL){
        root = getNode(val);
    }else
        insert(root, val); 

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