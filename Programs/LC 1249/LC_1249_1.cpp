#include<iostream>
#include<fstream>
#include<vector>
#include<stack>

using namespace std;

string minRemoveToMakeValid(string s){
    stack<int> stk; 

    for(int i = 0; i < s.length(); i++){
        if(isalpha(s[i])) continue; 

        if(!stk.empty() && ((s[stk.top()] == '(') && (s[i] == ')')))
            stk.pop();
        else
            stk.push(i); 
    }

    string result = ""; 
    for(int i = s.length() - 1; i >= 0; --i){
        if((!stk.empty()) && (i == stk.top()))
            stk.pop(); 
        else    
            result = s[i] + result; 
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
        string s; fin>>s; 

        cout<<minRemoveToMakeValid(s)<<endl; 
        
        // ===== END =====
    }
    
    return 0; 
}