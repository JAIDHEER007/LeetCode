#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std; 

bool containsDuplicate(vector<int> arr){
    unordered_map<int, bool> umap;

    for(int i = 0; i < arr.size(); i++){
        if(umap[arr[i]]) return true; 
        umap[arr[i]] = true; 
    }

    return false; 
}

int main(){
    int n; 
    cin>>n; 

    vector<int> arr(n); 
    for(int i = 0; i < n; i++)
        cin>>arr[i]; 

    cout<<boolalpha<<containsDuplicate(arr)<<endl; 

    return 0; 
}