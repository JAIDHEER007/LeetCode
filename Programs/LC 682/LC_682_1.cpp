// Runtime: 8ms
// Faster Than: 71.34%
// Memory Usage: 8.3MB
// Less Than: 69.92%

#include<iostream>
#include<fstream>
#include<vector>
#include<stack>
#include<sstream>

using namespace std;

int calPoints(vector<string>& ops) {
    stack<int> stk; 

    int n = ops.size(); 
    for(int i = 0; i < n; ++i){
        if(ops[i] == "+"){
            int prev1 = stk.top(); 
            stk.pop(); 
            int prev2 = stk.top(); 
            stk.push(prev1); 
            stk.push(prev1 + prev2);  
        }else if(ops[i] == "D")
            stk.push((stk.top()) * 2); 
        else if(ops[i] == "C")
            stk.pop(); 
        else
            stk.push(stoi(ops[i])); 
    }
            
    int sum = 0; 
    while(!stk.empty()){
        sum += stk.top(); 
        stk.pop(); 
    }


    return sum; 
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
        string data; getline(fin, data); 

        vector<string> ops; 
        string operation; 
        stringstream ss(data); 

        while(ss >> operation)
            ops.push_back(operation); 

        cout<<calPoints(ops)<<endl; 
        
        
        // ===== END =====
    }
    
    return 0; 
}