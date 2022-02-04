#include<iostream>
#include<fstream>
#include<vector>
#include<unordered_map>

using namespace std; 

int findMaxLength(vector<int>& arr){
    int n = arr.size(); 

    int maxLength = 0; 
    unordered_map<int, int> umap; 
    int count = 0; 

    for(int i = 0; i < n; i++){
        if(arr[i]) ++count; 
        else --count; 

        if(count == 0) maxLength = max(maxLength, (i + 1)); 

        if(umap.find(count) != umap.end())
            maxLength = max(maxLength, (i - umap[count]));
        else umap[count] = i; 
    }

    return maxLength; 
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