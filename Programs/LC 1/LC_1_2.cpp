// 18ms

// O(n)
// O(n) Space
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std; 

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> umap; 
    int n = nums.size(); 
    for(int i = 0; i < n; i++){
        umap[nums[i]] = i; 
    }

    for(int i = 0; i < n; i++){
        if(umap.find(target - nums[i]) != umap.end()){
            if(i != umap[target - nums[i]])
                return {i, umap[target - nums[i]]}; 
        }
    }

    return {-1, -1}; 
}

int main(){
    int n; 
    cin>>n; 

    vector<int> arr(n); 

    for(int i = 0; i < n; i++)
        cin>>arr[i]; 

    int target; cin>>target; 

    vector<int> result = twoSum(arr, target); 

    cout<<result[0]<<" "<<result[1]<<endl; 

    return 0; 
}