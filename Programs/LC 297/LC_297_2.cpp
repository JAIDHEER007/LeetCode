// Runtime: 44ms
// Faster Than: 91.45%
// Memory Usage: 32.3MB
// Less Than: 48.57%

// LeetCode input and output compatible

#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<queue>

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

void inorder(TreeNode* root){
    if(root == NULL) return; 

    inorder(root->left); 
    cout<<(root->val)<<" "; 
    inorder(root->right); 
}

void preorder(TreeNode* root){
    if(root == NULL) return; 

    cout<<(root->val)<<" "; 
    preorder(root->left); 
    preorder(root->right); 
}

void postorder(TreeNode* root){
    if(root == NULL) return; 

    postorder(root->left); 
    postorder(root->right); 
    cout<<(root->val)<<" "; 
}

void levelorder(TreeNode* root){
    if(root == NULL){
        cout<<"EMPTY TREE"<<endl; 
        return; 
    }

    queue<TreeNode*> q; 
    q.push(root); 

    while(!q.empty()){
        TreeNode* curr = q.front(); 
        q.pop(); 

        cout<<(curr->val)<<" "; 
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }

    cout<<endl;
}

int maxDepth(TreeNode* root){
    if(root == NULL) return 0; 

    // Remove this afterwards
    if((root->left == NULL) && (root->right == NULL)) return 1; 

    int leftHeight = (root->left)?(maxDepth(root->left)):0; 
    int rightHeight = (root->right)?(maxDepth(root->right)):0;

    return max(leftHeight, rightHeight) + 1; 
}

string serialize(TreeNode* root){
    if(root == NULL) return "null"; 

    int maxLevel = maxDepth(root); 

    queue<pair<TreeNode*, int>> q; 

    // Push the root to Q
    q.push({root, 1}); 

    // mainitain a result string
    string res = ""; 

    while(!q.empty()){
        // Front element in the queue
        pair<TreeNode*, int> fElement = q.front(); 

        // pop the Q
        q.pop(); 

        // Current Node
        TreeNode* currNode = fElement.first; 

        // Current Level
        int currLevel = fElement.second; 

        if(currNode){
            // currNode is not a null node
            // Add it to the result string
            res += (to_string(currNode->val) + " "); 

            // Add the child nodes

            // left node
            if(currNode->left){
                // Simply push the node to Q
                // with increased level state
                q.push({(currNode->left), (currLevel + 1)}); 
            }else{
                // Child node is NULL
                // Check the nextLevel with maxLevel before adding it to the Q
                // Pairing the level information with null node is not necessary as it not used 
                // while parsing

                // next level (currLevel + 1) should be less than or equal to maxLevel
                // Then add the null node
                if((currLevel + 1) <= maxLevel)
                    q.push({NULL, 0}); 
            }

            // Right Node
            if(currNode->right)
                q.push({(currNode->right), (currLevel + 1)}); 
            else{
                if((currLevel + 1) <= maxLevel)
                    q.push({NULL, 0}); 
            }

        }else{
            // if the current Node is NULL
            // Just add it to the result string as "null"
            res += "null "; 

            // No children or extra levels will be added
        }
    }

    // extra space will be added
    // pop that 
    res.pop_back(); 

    return res; 
}

TreeNode* deserialize(string data) {
    stringstream ss(data); 

    string token; 
    vector<string> tokens; 

    // Storing all the tokens into a vector for ease of access
    while(ss >> token)
        tokens.push_back(token); 

    int tokenCount = tokens.size(); 

    int tPtr = 0; // Token pointer

    // If number of tokens is 0 ==> No token
    // First Token is zero then "null"
    // Then the tree is empty so just return null
    if((tokenCount == 0) || (tokens[tPtr] == "null")) return NULL; 

    // Now Root Node is present
    // Create the root node
    TreeNode* root = new TreeNode(stoi(tokens[tPtr])); 

    // Maintain a Queue for level order traversal
    queue<TreeNode*> q; 

    // Push the root node
    q.push(root); 

    // Increment the token pointer
    ++tPtr; 

    // Start the loop
    while(!q.empty()){
        // Take the front node into consideration
        TreeNode* currNode = q.front(); 

        // Dequeue the front node
        q.pop(); 

        // Add the nodes from tokens vector

        // Check if the tokenPointer is less than tokenCount
        
        // left node
        if(tPtr < tokenCount){
            // Check if the token is not null token
            if(tokens[tPtr] != "null"){
                // Create the TreeNode
                TreeNode* node = new TreeNode(stoi(tokens[tPtr])); 

                currNode->left = node; 
                q.push(node); 
            }
            // the token has been parsed. So increment the token pointer
            ++tPtr;
        }

        // right node
        if(tPtr < tokenCount){
            // Check if the token is not null token
            if(tokens[tPtr] != "null"){
                // Create the TreeNode
                TreeNode* node = new TreeNode(stoi(tokens[tPtr])); 

                currNode->right = node; 
                q.push(node); 
            }
            // the token has been parsed. So increment the token pointer
            ++tPtr;
        }
    }

    return root; 
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
        string data; getline(fin, data); 
        
        TreeNode* root = deserialize(data); 

        // inorder(root); cout<<endl; 
        // preorder(root); cout<<endl; 
        // postorder(root); cout<<endl; 
        // levelorder(root); cout<<endl; 

        string serialData = serialize(root); 

        cout<<boolalpha<<(serialData == data)<<endl; 

        // ===== END =====
    }
    
    return 0; 
}