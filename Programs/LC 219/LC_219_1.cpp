#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std; 

bool containsNearbyDuplicate(vector<int> arr, int k){
    unordered_map<int, int> umap; 

    for(int i = 0; i < arr.size(); ++i){
        // if the element is not present in the map 
        // insert it into the map

        if(umap.find(arr[i]) == umap.end())
            umap[arr[i]] = i; 
        else{
            // The element is present
            // Check the difference between the oldIndex and newIndex; 
            // if newIndex - oldIndex <= k then return true; 
            // Else update the oldIndex with newIndex
            if((i - umap[arr[i]]) <= k) return true; 
            umap[arr[i]] = i; 
        }
    }

    return false; 
}

int main(){
    int n; 
    cin>>n; 

    vector<int> arr(n); 

    for(int i = 0; i < n; i++)
        cin>>arr[i]; 

    int k; cin>>k; 

    cout<<boolalpha<<containsNearbyDuplicate(arr, k)<<endl; 

    return 0; 
}