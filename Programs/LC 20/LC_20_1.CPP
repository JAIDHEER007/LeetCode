#include<iostream>
#include<fstream>
#include<vector>
#include<stack>

using namespace std;

bool isValid(string data){
    stack<char> stk; 

    int n = data.length(); 
    for(int i = 0; i < n; i++){
        if((data[i] == '(') || (data[i] == '{') || (data[i] == '[')){   // If open bracket push it to the stack
            stk.push(data[i]); 
            continue; 
        }  

        if(stk.empty()) // If stack is empty. First bracket is closing bracket. Return False
            return false; 

        // If the bracket is closing bracket. 
        // Check and Pop
        char sTop = stk.top(); 
        stk.pop(); 

        switch(data[i]){
            case ')':
                if(sTop != '(') return false; 
                break; 
            case '}':
                if(sTop != '{') return false; 
                break; 
            case ']':
                if(sTop != '[') return false; 
                break; 
        }
    }
    return stk.empty(); 
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
        string data; fin>>data; 

        cout<<boolalpha<<isValid(data)<<endl; 
        
        // ===== END =====
    }
    
    return 0; 
}