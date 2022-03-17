#include<iostream>
#include<fstream>
#include<vector>
#include<stack>

using namespace std;

// void printSTK(stack<string> stk){
//     while(!stk.empty()){
//         cout<<(stk.top())<<" "; 
//         stk.pop(); 
//     }
//     cout<<endl; 
// }

int scoreOfParentheses(string s){
    stack<string> stk; 

    for(int i = 0; i < s.length(); ++i){
        if(s[i] == '('){
            stk.push("("); 
        }else{
            if(stk.top() == "("){
                stk.pop(); 
                stk.push("1"); 
            }else{
                int sum = 0; 
                while((!stk.empty()) && stk.top() != "("){
                    sum += stoi(stk.top());
                    stk.pop(); 
                }
                stk.pop(); 
                stk.push(to_string(2 * sum)); 
            }
        }
    }

    int result = 0;     

    while(!stk.empty()){
        result += stoi(stk.top()); 
        stk.pop(); 
    }

    return result; 
}

int main(){
    // change the number of test cases
    int nInputs = 6;

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

        cout<<scoreOfParentheses(data)<<endl; 
        
        // ===== END =====
    }
    
    return 0; 
}