#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>

using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int flipCount = 0; 
        while(start || goal){
            flipCount += ((start & 1) ^ (goal & 1));
            start >>= 1; 
            goal >>= 1 ;
        }

        return flipCount; 
    }
};


int main(){
    // change the number of test cases
    int nInputs = 5;

    // Creating a Solution Object
    Solution* solObj = new Solution(); 

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
        int start, goal; 
        fin>>start>>goal; 

        cout<<(solObj->minBitFlips(start, goal))<<endl; 
        
        // ===== END =====
    }
    
    return 0; 
}