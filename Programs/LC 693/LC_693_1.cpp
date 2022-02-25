#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

bool hasAlternatingBits(int n){
    int prevBit = -1; 
    while(n){
        int bit = (n & 1); 
        if(prevBit == -1)
            prevBit = bit; 
        else{
            if(bit == prevBit) return false; 
            prevBit = bit; 
        }
        n >>= 1; 
    }

    return true; 
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
        int n; 
        fin >> n; 

        cout<<boolalpha<<hasAlternatingBits(n)<<endl; 
        // ===== END =====
    }
    
    return 0; 
}