// Binary Exponentation 

#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

long binExp(int base, int exp){
    long result = 1; 
    long tempBase = (long)base; 

    while(exp){
        if(exp & 1)
            result *= tempBase; 
        tempBase *= tempBase; 
        exp >>= 1; 
    }

    return result; 
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
        int base; fin>>base; 
        int exp; fin>>exp; 

        cout<<binExp(base, exp)<<endl; 
        // ===== END =====
    }
    
    return 0; 
}