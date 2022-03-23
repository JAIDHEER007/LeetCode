#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int brokenCalc(int start, int target) {
    int operations = 0; 
    while(target > start){
        if(target & 1) ++target; 
        else target >>= 1; 
        ++operations; 
    }
    return (operations + (start - target)); 
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
        int start; fin>>start; 
        int target; fin>>target; 

        cout<<brokenCalc(start, target)<<endl; 
        
        // ===== END =====
    }
    
    return 0; 
}