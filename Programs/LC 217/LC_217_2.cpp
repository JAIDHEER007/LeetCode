#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 

bool containsDuplicate(vector<int> arr){
    sort(arr.begin(), arr.end()); 
    for(int i = 1; i < arr.size(); i++)
        if(arr[i - 1] == arr[i]) return true; 

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