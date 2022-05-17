#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>

using namespace std;

int sumOddLengthSubarrays(vector<int> &arr){
    int n = arr.size(); 
    vector<int> prefixArr(n + 1); 

    for(int i = 0; i < n; ++i)
        prefixArr[i + 1] = (prefixArr[i] + arr[i]); 

    int sum = 0; 
    for(int i = 1; i <= n; i += 2){
        for(int k = 0, j = i; j <= n; ++j, ++k)
            sum += (prefixArr[j] - prefixArr[k]); 
    }

    return sum; 
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
        vector<int> arr(n); 

        for(int i = 0; i < n; ++i)
            fin>>arr[i]; 

        
        cout<<sumOddLengthSubarrays(arr)<<endl; 
        
        // ===== END =====
    }
    
    return 0; 
}