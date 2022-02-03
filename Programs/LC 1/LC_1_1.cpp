// O(n²)
// O(1) Space
#include<iostream>
#include<vector>

using namespace std; 

vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size(); 
    for(int i = 0; i < n; i++){
        for(int j = (i + 1); j < n; j++)
            if(nums[i] + nums[j] == target) return {i, j}; 
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