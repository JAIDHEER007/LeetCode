// Without using inbuilt stack

#include<iostream>
#include<fstream>
#include<vector>
// #include<stack>
#include<sstream>

using namespace std;

int calPoints(vector<string>& ops) {
    vector<int> stk(1001, 0); 
    int top = -1; 

    int n = ops.size(); 
    for(int i = 0; i < n; ++i){
        if(ops[i] == "+"){
            stk[top + 1] = (stk[top] + stk[top - 1]); 
            ++top; 
        }
        else if(ops[i] == "D"){
            stk[top + 1] = stk[top] * 2; 
            ++top; 
        }
        else if(ops[i] == "C")
            --top; 
        else
            stk[++top] = stoi(ops[i]);
    }
            
    int sum = 0; 
    while(top != -1)
        sum += stk[top--]; 

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