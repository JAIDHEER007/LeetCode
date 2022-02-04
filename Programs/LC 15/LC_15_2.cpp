// Using 2 sum 
// TLE
// 315 / 318 cases passed
// Possible Complexity: O(n²)

#include<iostream>
#include<fstream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std; 

vector<vector<int>> threeSum(vector<int> arr){
    vector<vector<int>> result; 

    int n = arr.size(); 
    sort(arr.begin(), arr.end()); 
    unordered_map<int, bool> uniq1; 

    for(int i = 0; i < n; i++){
        if(uniq1[arr[i]]) continue; 
        uniq1[arr[i]] = true; 

        int target = -1 * arr[i]; 
        unordered_map<int, int> umap; 
        unordered_map<int, bool> uniq2; 

        for(int j = i + 1; j < n; j++){
            if(umap.find(target - arr[j]) != umap.end()){
                if(uniq2[arr[j]]) continue; 
                else uniq2[arr[j]] = true; 
                result.push_back({arr[i], arr[j], arr[umap[target - arr[j]]]}); 
                // break; 
            }else
                umap[arr[j]] = j; 
        }
    }

    return result; 
}

int main(){
    // change the number of test cases
    int nInputs = 6;

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
        for(int i = 0; i < n; fin>>arr[i], i++); 

        vector<vector<int>> result = threeSum(arr); 

        for(vector<int> row:result){
            for(int element:row)
                cout<<element<<" "; 
            cout<<endl; 
        }

        // ===== END =====
    }
    
    return 0; 
}