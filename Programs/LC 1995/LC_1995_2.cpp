// Runtime: 256ms
// Faster Than: 16.86%
// Memory Usage: 10.5 MB
// Less Than: 50.29%
// Time Complexity: O(n⁴)


#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std; 

int countQuadruplets(vector<int> arr){
    int count = 0; 
    int n = arr.size(); 
    unordered_map<int, int> umap; 

    for(int i = 1; i < n; ++i){
        for(int j = 0; j < i; ++j)
            ++umap[arr[i] + arr[j]];

        for(int j = (i + 2); j < n; ++j)
            count += umap[arr[j] - arr[i + 1]]; 
    }

    return count; 
}

int main(){
    int n; 
    cin>>n; 

    vector<int> arr(n); 
    for(int i = 0; i < n; i++)
        cin>>arr[i]; 
    
    cout<<countQuadruplets(arr)<<endl; 

    return 0; 
}