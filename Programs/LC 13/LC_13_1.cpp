#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>

using namespace std;

int romanToInt(string s) {
    int sum = 0; 
    int prevNum = -1; 

    for(int i = 0; i < s.length(); ++i){
        int rn = 0; 
        switch(s[i]){
            case 'M': rn = 1000; break; 
            case 'D': rn = 500; break; 
            case 'C': rn = 100; break; 
            case 'L': rn = 50; break; 
            case 'X': rn = 10; break; 
            case 'V': rn = 5; break; 
            case 'I': rn = 1; break;
        }

        if(prevNum == -1){
            sum = rn; 
        }else{
            if(prevNum < rn){
                sum -= prevNum; 
                sum += (rn - prevNum);
            }else
                sum += rn; 
        }
        prevNum = rn; 
    }

    return sum; 
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

        cout<<romanToInt(s)<<endl; 
        
        // ===== END =====
    }
    
    return 0; 
}