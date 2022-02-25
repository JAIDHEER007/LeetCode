#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int setBits(int n){
    int bits = 0; 
    while(n){
        if(n & 1) ++bits; 
        n >>= 1; 
    }
    return bits; 
}

bool checkPrime(int bits){
    return (bits == 2) || (bits == 3) || (bits == 5) || (bits == 7) || 
           (bits == 11) || (bits == 13) || (bits == 17) || (bits == 19); 
}

int countPrimeSetBits(int left, int right){
    int count = 0; 
    while(left <= right){
        if(checkPrime(setBits(left))) ++count; 
        ++left; 
    }

    return count; 
}

int main(){
    // change the number of test cases
    int nInputs = 2;

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
        int left; fin>>left; 
        int right; fin>>right; 

        cout<<countPrimeSetBits(left, right)<<endl; 

        // ===== END =====
    }

    return 0; 
}