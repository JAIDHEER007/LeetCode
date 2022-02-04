#include<iostream>
#include<fstream>
#include<vector>

using namespace std; 

int findMaxLength(vector<int>& arr){
    int n = arr.size(); 
    // cout<<n<<endl; 

    arr[0] = (arr[0])?(-1):(1); 

    for(int i = 1; i < n; i++){
        if(arr[i] == 0) arr[i] = (arr[i - 1] + 1); 
        else arr[i] = (arr[i - 1] - 1);
    }

    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" "; 
    cout<<endl; 

    for(int i = n - 1; i >= 0; i--){
        if(arr[i] == 0) return (i + 1); 
    }

    return 0; 
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
        
        int n; 
        fin>>n; 

        vector<int> arr(n); 

        for(int i = 0; i < n; fin>>arr[i], i++); 

        cout<<findMaxLength(arr)<<endl; 
        
        // ===== END =====
    }
    
    return 0; 
}