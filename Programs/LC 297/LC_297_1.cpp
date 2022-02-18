// Serialize function Failing for Very Very Very Large Test Case
// Test Case: https://raw.githubusercontent.com/JAIDHEER007/Random-Programs/main/LC_297_52_TC_TLE.txt
// Failing when finding the total node count by 2ᵐᵃˣᴰᵉᵖᵗʰ

#include<iostream>
#include<vector>
#include<queue>
#include<sstream>
#include<fstream>

using namespace std; 

typedef struct node{
    int value; 
    node* left; 
    node* right; 

    node(){
        value = 0; 
        left = NULL; 
        right = NULL; 
    }

    node(int _value){
        value = _value; 
        left = NULL; 
        right = NULL; 
    }
} node;

void inorder(node* root){
    if(root == NULL) return; 

    inorder(root->left); 
    cout<<(root->value)<<" "; 
    inorder(root->right); 
}

void preorder(node* root){
    if(root == NULL) return; 

    cout<<(root->value)<<" "; 
    preorder(root->left); 
    preorder(root->right); 
}

void postorder(node* root){
    if(root == NULL) return; 

    postorder(root->left); 
    postorder(root->right); 
    cout<<(root->value)<<" "; 
}

void levelorder(node* root){
    if(root == NULL){
        cout<<"EMPTY TREE"<<endl; 
        return; 
    }

    queue<node*> q; 
    q.push(root); 

    while(!q.empty()){
        node* curr = q.front(); 
        q.pop(); 

        cout<<(curr->value)<<" "; 
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }

    cout<<endl;
}

node* deserialize(string data){
    // To tokenize the string
    // Split at spaces
    stringstream ss(data); 
    
    // Contains the tokens from stringstream
    string token; 

    node* root = NULL;
    // Level Of the Binary Tree 
    int level = 0; 
    
    // Count of nodes in the binary tree
    int count = 0; 

    // To maintain the order of nodes
    queue<node*> q; 

    // Will be Inverted.
    // If left the node will be added as left node
    // If right the node will be added as right node
    bool left = true; 

    // Each token will be gathered
    while (ss >> token){
        // If the level is zero
        // The tree is not formed
        // Root node will be formed
        if(level == 0){
            // If token is not NULL btw NULL is represented by * 
            // Form the root
            if(token != "*"){
                // The starting the node will be the root node
                root = new node(stoi(token)); 

                // Increase the level
                ++level; 

                // Push the node to Queue
                q.push(root); 
            }else return root;  // The tree will not form as the root is NULL so return NULL 
        }else{
            // The tree was already part formed

            // Get the front node from Queue
            // We will connect the nodes to this node
            node* currNode = q.front(); 

            // The token is NULL
            if(token != "*"){
                // Form the node
                node* newNode = new node(stoi(token)); 

                // if the left is True 
                // Add the newNode as left node to currNode
                // Else add the newNode as right node to currNode
                if(left) currNode->left = newNode; 
                else currNode->right = newNode; 

                // Push the newNode to Queue
                q.push(newNode); 
            }else q.push(NULL); // We have to push NULL so that Queue is in correct order

            // Increase the node count
            ++count; 

            // If the node count is divisible by 2 
            // then he currNode has 2 children 
            // So Pop the Queue
            if(count % 2 == 0) q.pop(); 

            // if count equals to 2ˡᵉᵛᵉˡ then the Number of nodes in the level 
            // Got filled so increase the level and reset the count
            if(count == (1 << level)){
                ++level; 
                count = 0; 
            }

            // Invert the left boolean variable for every token
            left = !left; 
        }
    }

    // There is no need to fear for condition like NULL->left or NULL->right
    // If the data is provided as if the Tree is of perfect binary tree

    return root;     
}

int maxDepth(node* root){
    if(root == NULL) return 0; 
    if((root->left == NULL) && (root->right == NULL)) return 1; 

    int leftHeight = (root->left)?(maxDepth(root->left)):0; 
    int rightHeight = (root->right)?(maxDepth(root->right)):0;

    return max(leftHeight, rightHeight) + 1; 
}

string serialize(node* root){
    string data = ""; 

    queue<node*> q; 

    if(root == NULL)
        return "*";
    q.push(root); 

    int limit = (1 << maxDepth(root)) - 1; 
    int nodeCount = 0;  

    while(!q.empty() && (nodeCount != limit)){
        node* curr = q.front(); 
        q.pop();
        ++nodeCount; 

        if(curr == NULL){
            data += "* "; 
            q.push(NULL); 
            q.push(NULL);
        }else{
            data += (to_string(curr->value) + " "); 
            q.push(curr->left);
            q.push(curr->right); 
        }
    }
    data.pop_back(); 

    return data; 
}

int main(){
    // change the number of test cases
    int nInputs = 4;

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
        string inputData; fin>>inputData; 

        node* root = deserialize(inputData); 
        string serialData = serialize(root); 


        if(inputData == serialData)
            cout<<boolalpha<<true<<endl; 
        else{
            cout<<inputData<<endl; 
            cout<<serialData<<endl; 
        }
        
        // ===== END =====
    }
    
    return 0; 
}