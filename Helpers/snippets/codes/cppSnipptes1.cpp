#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>

using namespace std;

// Implement the solution class 
// With the given methods
class Solution {
    public:
    
};

int main(){
    // change the number of test cases
    int nInputs = 0;

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

        
        // ===== END =====
    }
    
    return 0; 
}