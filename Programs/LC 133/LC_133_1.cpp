// Runtime: 4ms
// Faster Than: 93.09%
// Memory Usage: 8.6 MB
// Less Than: 71.30% 

#include<iostream>
#include<vector> 
#include<unordered_map>
#include<stack>

using namespace std; 

class Node{
    public:
        int val; 
        vector<Node*> neighbors; 

        Node(){
            this->val = 0; 
            this->neighbors = vector<Node*>(); 
        }
        Node(int val){
            this->val = val; 
            this->neighbors = vector<Node*>(); 
        }
        Node(int val, vector<Node*> neighbors){
            this->val = val; 
            this->neighbors = neighbors; 
        }
}; 

Node* makeGraph1(){
    Node* n1 = new Node(1); 
    Node* n2 = new Node(2); 
    Node* n3 = new Node(3); 
    Node* n4 = new Node(4); 
    
    n1->neighbors = {n2, n4}; 
    n2->neighbors = {n1, n3}; 
    n3->neighbors = {n2, n4}; 
    n4->neighbors = {n1, n3}; 

    return n1; 
}

Node* cloneGraph(Node* node){
    if(node == NULL) return NULL; 

    unordered_map<int, bool> visited; 
    unordered_map<int, Node*> nodes; 
    stack<Node*> stk; 
    stk.push(node); 
    nodes[node->val] = new Node(node->val); 

    while(!stk.empty()){
        Node* top = stk.top(); 
        stk.pop(); 
        int value = top->val; 

        if(visited[value]) continue; 
        visited[value] = true; 

        vector<Node*> neighbors = top->neighbors; 
        for(int i = 0; i < size(neighbors); i++){
            Node* nodeAddress = NULL; 
            int nValue = neighbors[i]->val; 
            if(!visited[neighbors[i]->val])
                stk.push(neighbors[i]); 
            nodes[value]->neighbors.push_back((nodes[nValue])?(nodes[nValue]):(nodes[nValue] = new Node(nValue))); 
        }   
    }
    return nodes[1]; 
}

void printGraph(Node* n1){
    unordered_map<Node*, bool> visited; 
    stack<Node*> stk; 
    stk.push(n1); 

    while(!stk.empty()){
        Node* top = stk.top(); 
        stk.pop(); 

        if(!visited[top]) cout<<(top->val)<<endl; 
        visited[top] = true; 

        vector<Node*> neighbors = (top->neighbors); 

        for(int i = 0; i < size(neighbors); i++){
            if(!visited[neighbors[i]]) 
                stk.push(neighbors[i]); 
        }
    }
    cout<<endl; 
}

int main(){

    Node* n1 = makeGraph1(); 
    Node* new_n1 = cloneGraph(n1); 

    printGraph(n1); 
    printGraph(new_n1); 

    return 0; 
}
