// MF code didn't do good
// Have to use NeedForSpeed snippet to make it barely pass
// Runtime: 1156 ms
// Faster Than: 8.28%
// Memoery Usage: 129.4 mb
// Less Than: 12.72% :(



#include<iostream>
#include<vector>
#include<string>

using namespace std; 

typedef struct node{
    node* children[2]; 
    bool isEnd; 

    node(){
        isEnd = false; 
        children[0] = children[1] = NULL; 
    }
} node; 

void insert(node* root, string txt){
    node* curr = root; 

    for(int i = 0; i < txt.length(); i++){
        int index = txt[i] - '0'; 
        if(curr->children[index] == NULL) 
            curr->children[index] = new node; 
        curr = curr->children[index]; 
    }

    curr->isEnd = true; 
}

bool search(node* root, string key){
    node* curr = root; 
    for(int i = 0; i < key.length(); ++i){
        int index = key[i] - '0'; 
        if(curr->children[index] == NULL) return false; 
        curr=  curr->children[index]; 
    }

    return curr->isEnd; 
}

void insertInput(vector<int> arr, node* root){
    int maxNumber = INT_MIN; 
    int n = arr.size(); 

    for(int i = 0; i < n; i++)
        maxNumber = max(maxNumber, arr[i]); 

    int maxBC = 0;
    while(maxNumber){
        ++maxBC; 
        maxNumber >>= 1; 
    } 

    for(int i = 0; i < n; i++){
        string bin = ""; 
        int temp = arr[i]; 

        while(temp){
            bin = to_string(temp & 1) + bin;
            temp >>= 1;  
        }
        insert(root, (string(maxBC - bin.length(), '0') + bin)); 
    }
}

node* splittingNode(node* root){
    node* curr = root; 

    while((curr->children[0] == NULL) || (curr->children[1] == NULL)){
        if((curr->children[0] == NULL) && (curr->children[1] == NULL)) return NULL; 
        
        if(curr->children[0]) curr = curr->children[0]; 
        else curr = curr->children[1]; 
    }

    return curr; 
}

void dfs(int &maxXor, node* lnode, node* rnode, int currXor = 1){
    // cout<<currXor<<endl; 
    // currXor*= 2; 
    if(rnode->children[0]){
        // 0 is present in the right subtree
        // Checking if 1 is present in the left subtree
        if(lnode->children[1]){
            // If present then 0 ^ 1 = 1
            // so multiply the currXor with 2
            // And pass to the recursion
            dfs(maxXor, lnode->children[1], rnode->children[0], (1 + (2 * currXor))); 
        }else{
            // Just pass the recursive call with lnode->children[0]; 
            // Dont Multiply with 2 
            // as 0 ^ 0 = 0
            dfs(maxXor, lnode->children[0], rnode->children[0], (2 * currXor)); 
        } 
    }

    // The conditions will interchange
    if(rnode->children[1]){
        if(lnode->children[0]){
            // Iass to the recursion
            dfs(maxXor, lnode->children[0], rnode->children[1], (1 + (2 * currXor))); 
        }else{
            // Jus 0 = 0
            dfs(maxXor, lnode->children[1], rnode->children[1], (2 * currXor)); 
        } 
    }

    // Base Case
    if(lnode->isEnd){
        maxXor = max(maxXor, currXor); 
        return; 
    }
}

int findMaximumXOR(vector<int> arr){
    node* root = new node; 
    insertInput(arr, root); 

    node* splitNode = splittingNode(root); 

    if(splitNode == NULL) return 0; 

    int maxXor = INT_MIN; 
    dfs(maxXor, splitNode->children[0], splitNode->children[1]); 

    return maxXor; 
}

int main(){
    int n; 
    cin>>n; 

    vector<int> arr(n); 
    for(int i = 0; i < n; i++)
        cin>>arr[i]; 
    

    // cout<<boolalpha<<search(root, "0001110")<<endl; // 14
    // cout<<boolalpha<<search(root, "1010011")<<endl; // 83
    // cout<<boolalpha<<search(root, "1011011")<<endl; // 91
    // cout<<boolalpha<<search(root, "1010000")<<endl; // 80

    // cout<<boolalpha<<search(root, "0001010")<<endl; // 14
    // cout<<boolalpha<<search(root, "1010111")<<endl; // 83
    // cout<<boolalpha<<search(root, "1001011")<<endl; // 91
    // cout<<boolalpha<<search(root, "1010100")<<endl; // 80

    // cout<<root<<endl;
    // cout<<splittingNode(root)<<endl;  

    cout<<findMaximumXOR(arr)<<endl; 

    return 0; 
}

/*
Sample Input:

12
14 70 53 83 49 91 36 80 92 51 66 70

14 == > 0001110
70 == > 1000110
53 == > 0110101
83 == > 1010011
49 == > 0110001
91 == > 1011011
36 == > 0100100
80 == > 1010000
92 == > 1011100
51 == > 0110011
66 == > 1000010
70 == > 1000110

*/
