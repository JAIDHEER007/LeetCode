// Time Complexity: O(n)

#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

vector<int> countBits(int n) {
    if(n == 0) return {0}; 
    if(n == 1) return {0,1}; 

    vector<int> bits{0, 1}; 

    int prev2Power = -1;     // Start value is not needed as loop starts from 2 the value will assigned to 2 
    for(int i = 2; i <= n; i++){
        if((i & (i - 1)) == 0)
            prev2Power = i; 
        int diff = i - prev2Power; 
        bits.push_back(bits[diff] + 1); 
    }

    return bits; 
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
        vector<int> results = countBits(n); 

        for(int result:results)
            cout<<result<<" "; 
        cout<<endl; 

        // ===== END =====
    }
    
    return 0; 
}