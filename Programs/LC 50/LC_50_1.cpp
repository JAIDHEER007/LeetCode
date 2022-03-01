#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

double myPow(double base, int exp){
    if(exp == 0) return 1; 
    
    if(exp < 0){
        base = 1.00 / base; 
        if(exp == INT_MIN) 
            exp = INT_MAX - 1;  
        else
            exp *= -1; 
    }

    // Base Case
    if(exp == 1) 
        return base; 

    int a = exp >> 1; 
    int b = exp & 1; 

    return myPow((base * base), a) * ((b)?(base):1); 
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
        double x; fin>>x; 
        int n; fin>>n; 

        cout<<myPow(x, n)<<endl; 
        
        // ===== END =====
    }
    
    return 0; 
}