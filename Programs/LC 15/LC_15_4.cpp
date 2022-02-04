// Using 2 sum with 2 pointers
// Used with NeedForSpeed
// Possible Complexity: O(n²)

// Runtime: 76ms
// Faster than: 83.02%
// Memory Usage: 22.2MB
// Less Than: 33.68%

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

    for(int i = 0; i < n; i++){
        if((i != 0) && (arr[i] == arr[i - 1])) continue;

        int target = arr[i]; 
        int left = i + 1; 
        int right = n - 1; 

        unordered_map<int, bool> uniq; 
        while(left < right){
            if(target + arr[left] + arr[right] < 0)
                ++left; 
            else if(target + arr[left] + arr[right] > 0)
                --right; 
            else{
                if(!uniq[arr[left]]){
                    result.push_back({arr[i], arr[left], arr[right]});
                    uniq[arr[left]] = true; 
                }
                ++left; 
                --right; 
            }   
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

