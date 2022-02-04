// TLE: 21 / 564
// Possible Complexity: o(n³)

#include<iostream>
#include<fstream>
#include<vector>

using namespace std; 

bool isGood(vector<int> arr, int i, int j){
    int zCount = 0; 
    int oCount = 0; 

    for(;i <= j; i++){
        if(arr[i]) ++oCount;
        else ++zCount; 
    }

    return zCount == oCount; 
}

int findMaxLength(vector<int>& arr){
    int maxLength = 0; 
    int n = arr.size(); 
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(isGood(arr, i, j)) maxLength = max(maxLength, (j - i + 1)); 
        }
    }

    return maxLength; 
}

int main(){
    // change the number of test cases
    int nInputs = 4;

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
        fin>>n; 

        vector<int> arr(n); 

        for(int i = 0; i < n; fin>>arr[i], i++); 

        cout<<findMaxLength(arr)<<endl; 
        
        // ===== END =====
    }
    
    return 0; 
}