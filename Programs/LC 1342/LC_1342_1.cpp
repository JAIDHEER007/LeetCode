// Runtime: 6ms
// Faster Than: 6.24%
// Memory Usage: 5.8mb
// Less Than: 75.19%

// NeedForSpeed
// Runtime: 0ms
// Faster Than: 100.00%

#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>

using namespace std;

int numberOfSteps(int n){
    int count = 0; 

    while(n){
        if(n & 1)
            n = n - 1; 
        else    
            n >>= 1; 
        ++count; 
    }

    return count; 
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
        int n; fin>>n; 

        cout<<numberOfSteps(n)<<endl;
        
        // ===== END =====
    }
    
    return 0; 
}