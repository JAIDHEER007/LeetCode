#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

vector<int> decode(vector<int>& encoded, int first) {
    vector<int> ans;
    ans.push_back(first);
    ans.push_back(first^encoded[0]);
    for(int i=1; i<encoded.size(); i++){
        ans.push_back(encoded[i]^ans[i]);
    }
    return ans;
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
        int n; fin>>n; 
        vector<int> arr(n); 

        for(int i = 0 ; i< n; i++)
            fin>>arr[i]; 

        int first; fin>>first; 

        vector<int> result = decode(arr, first); 

        for(int i = 0 ; i < result.size(); i++)
            cout<<result[i]<<" "; 
        cout<<endl; 
        
        // ===== END =====
    }
    
    return 0; 
}