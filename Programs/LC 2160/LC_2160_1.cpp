#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>

using namespace std;

int minimumSum(int num){
    int *arr = new int[10](); 

    while(num){
        ++arr[num % 10]; 
        num /= 10; 
    }

    int num1 = 0; 
    int num2 = 0; 

    bool startWithNum1 = true; 
    for(int i = 0; i < 10; ++i){
        while(arr[i]){
            if(startWithNum1)
                num1 = (num1 * 10) + i; 
            else
                num2 = (num2 * 10) + i;
            --arr[i]; 
            startWithNum1 = !startWithNum1; 
        }
    }
    return num1 + num2; 
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

        cout<<minimumSum(n)<<endl; 
        
        // ===== END =====
    }
    
    return 0; 
}