#include<iostream>
#include<fstream>
#include<vector>
#include<unordered_map>

using namespace std;

int findPairs(vector<int> arr, int k){
    unordered_map<int, int> umap; 
    for(int i = 0; i < arr.size(); i++)
        ++umap[arr[i]]; 

    int res = 0; 
    for(unordered_map<int, int>::iterator itr = umap.begin(); itr != umap.end(); ++itr){
        if(k == 0){ // Should not point to self. counnt of element is greator than zero
            if(itr->second > 1) ++res; 
        }else if(umap.find(itr->first - k) != umap.end()){
            ++res; 
        }
    }

    return res; 
}

int main(){
    // change the number of test cases
    int nInputs = 3;

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
        for(int i = 0; i < n; i++)
            fin>>arr[i]; 
        
        int k; fin>>k;

        cout<<findPairs(arr, k)<<endl; 
        
        // ===== END =====
    }
    
    return 0; 
}