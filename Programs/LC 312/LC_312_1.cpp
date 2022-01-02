// LC 312 Burst Balloons
// Brute Force 
// Recursion with visited matrix

#include<iostream>
#include<vector>
using namespace std; 

int maxCoins(vector<int> arr){
    int coins = -1;
    int n = arr.size();

    // Adding the padding ones. 
    arr.insert(arr.begin(), 1); 
    arr.insert(arr.end(), 1);

    // Creating the visited matrix
    vector<bool> visited(arr.size(), false);  

    return coins; 
}

int main(){
    int n; 
    cin>>n; 

    vector<int> arr(n); 
    for(int i = 0; i < n; ++i)
        cin>>arr[i]; 

    cout<<maxCoins(arr)<<endl; 

    return 0; 
}