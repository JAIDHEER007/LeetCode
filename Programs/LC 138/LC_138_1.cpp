// Runtime: 17ms
// Faster Than: 28.69%
// Memory Usage: 11.1 MB
// Less Than: 87.91 %

#include<iostream>
#include<fstream>
#include<vector>
#include<unordered_map>

// Headers used for Debugging
#include<sstream>
#include<iomanip>

using namespace std;

class Node{
    public:
        int val; 
        Node* next; 
        Node* random; 

        Node(int _val){
            val = _val; 
            next = NULL; 
            random = NULL; 
        }
};

Node* makeLL(vector<vector<int>> data){
    int n = data.size(); 

    vector<Node*> nodes(n); 

    Node* dummyHead = new Node(0); 
    Node* curr = dummyHead; 

    for(int i = 0; i < n; i++){
        Node* newNode = new Node(data[i][0]); 
        nodes[i] = newNode; 
        curr->next = newNode; 
        curr = curr->next; 
    }

    curr = dummyHead->next; 

    // Populate the random pointer
    for(int i = 0; i < n; i++){
        if((data[i][1] != -1) && (data[i][1] < n))
            curr->random = nodes[data[i][1]]; 
        curr = curr->next; 
    }

    Node* head = dummyHead->next; 
    dummyHead->next = NULL; 
    delete dummyHead; 
    return head; 
}

Node* copyRandomList(Node* head){
    unordered_map<Node*, Node*> nodeMap; 
    
    Node* dummyHead = new Node(0); // Dummy Head for result Linked List
    
    // Creating the result linked list
    Node* currIll = head;           // Variable to hold the addresses of input linked list 
    Node* currRll = dummyHead;      // Variable to hold the addresses of result linked list 

    while(currIll){
        // Create the node of result linked list
        Node* newNode = new Node(currIll->val); 

        // Populate the nodeMap
        nodeMap[currIll] = newNode; 

        // Attach the node to result linked list
        currRll->next = newNode; 

        // Move the pointers to next Node
        currIll = currIll->next; 
        currRll = currRll->next;
    }

    // Remove the dummy head
    Node* rHead = dummyHead->next; 
    dummyHead->next = NULL; 
    delete dummyHead; 

    // Populating the random pointer of result linked list
    currIll = head; 
    currRll = rHead; 

    while(currIll){
        Node* randomPtr = currIll->random; 

        // If Random Pointer is Not Null
        if(randomPtr){
            // Find the corresponding node in result linked list
            Node* newRandom = nodeMap[randomPtr]; 

            // Make the above node as the random pointer
            currRll->random = newRandom; 
        }

        // Move the pointers to next Nodes
        currIll = currIll->next; 
        currRll = currRll->next; 
    }

    return rHead; 
}

// Functions related to debugging
string center(int width,string text){
	int len = text.length();
	if(width < len){ return text; }
	int diff = width - len; 
	int padding1 = diff/2;
	int padding2 = diff - padding1; 
	return string(padding1,' ') + text + string(padding2,' ');
}

string to_string(Node *address){
	stringstream ss;
	ss << address;
	return ss.str();
}

void debugLL(Node* head){
    if(head == NULL){
        cout<<"Linked List is Empty. Nothing to print"<<endl; 
        return; 
    }

    int nodeNumber = 0; 
    Node* curr = head; 

    cout<<string(117, '-')<<endl; 
    cout<<"|"<<center(10,"Node_No")<<"|"<<center(20,"Node Address")<<"|"
        <<center(20,"Node Value")<<"|"<<center(20, "Next Address")<<"|"
        <<center(20, "Random Address")<<"|"<<center(20, "Random Value")<<"|"<<endl;
    cout<<string(117, '-')<<endl; 
    
    while(curr){
        cout<<"|"<<center(10, to_string(nodeNumber))<<"|"<<center(20,to_string(curr))<<"|"
        <<center(20,to_string(curr->val))<<"|"<<center(20, ((curr->next)?(to_string(curr->next)):("Null")))<<"|"
        <<center(20, ((curr->random)?(to_string(curr->random)):("Null")))<<"|"
        <<center(20, ((curr->random)?(to_string(curr->random->val)):("Null Value")))<<"|"<<endl;

        curr = curr->next; 
        ++nodeNumber; 
    }

    cout<<string(117, '-')<<endl; 
}

int main(){
    // change the number of test cases
    int nInputs = 3;

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
        int n; fin>>n; 
        vector<vector<int>> data(n, vector<int>(2, 0)); 

        for(int i = 0; i < n; i++){
            fin>>data[i][0]>>data[i][1]; 
        }

        for(int i = 0; i < n; i++){
            cout<<data[i][0]<<" "<<data[i][1]<<endl; 
        }
        
        Node* head = makeLL(data); 
        cout<<"Original Linked List"<<endl; debugLL(head); 

        Node* rHead = copyRandomList(head); 

        cout<<"Result Linked List"<<endl; debugLL(rHead); 


        // ===== END =====
    }
    
    return 0; 
}