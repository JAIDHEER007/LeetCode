#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
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

TreeNode* makeTree_LO_str(string data){
    stringstream ss(data); 

    string token; 
    vector<string> tokens; 

    while(ss >> token)
        tokens.push_back(token); 

    int tokenCount = tokens.size(); 
    int tPtr = 0; // Token pointer

    if((tokenCount == 0) || (tokens[tPtr] == "null")) return NULL; 

    TreeNode* root = new TreeNode(stoi(tokens[tPtr])); 

    queue<TreeNode*> q; 
    q.push(root); 
    ++tPtr; 
    while(!q.empty()){
        TreeNode* currNode = q.front(); 

        q.pop(); 

        if(tPtr < tokenCount){
            if(tokens[tPtr] != "null"){
                TreeNode* node = new TreeNode(stoi(tokens[tPtr])); 

                currNode->left = node; 
                q.push(node); 
            }
            ++tPtr;
        }

        if(tPtr < tokenCount){
            if(tokens[tPtr] != "null"){
                TreeNode* node = new TreeNode(stoi(tokens[tPtr])); 

                currNode->right = node; 
                q.push(node); 
            }
            ++tPtr;
        }
    }

    return root; 
}

// Serialize and Desrialize code
// Using Preorder: Root -> Left -> Right

void preorderString(TreeNode* root, string &serialData){
    if(root == NULL){
        serialData += "* "; 
        return; 
    }

    serialData += (to_string(root->val) + " "); 
    preorderString(root->left, serialData); 
    preorderString(root->right, serialData); 
}

string serialize(TreeNode* root){
    string serialData = ""; 
    preorderString(root, serialData); 
    serialData.pop_back(); 

    return serialData; 
}

TreeNode* preorderContruct(stringstream &ss){
    string token; 
    ss >> token; 

    if((token == "*") || (token == "")) return NULL; 

    TreeNode* root = new TreeNode(stoi(token)); 

    root->left = preorderContruct(ss); 
    root->right = preorderContruct(ss); 

    return root; 
}

TreeNode* deserialize(string data){
    stringstream ss(data); 
    return preorderContruct(ss); 
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

        TreeNode* root = makeTree_LO_str(data); 
        
        string ser1 = serialize(root); 

        TreeNode* deser1 = deserialize(ser1); 

        string ser2 = serialize(deser1); 

        cout<<boolalpha<<(ser1 == ser2)<<endl; 

        // ===== END =====
    }
    
    return 0; 
}