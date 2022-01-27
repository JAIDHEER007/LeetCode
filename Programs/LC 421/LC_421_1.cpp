#include<iostream>
#include<vector>

using namespace std;

int findMaximumXOR(vector<int> arr){
    int maxXor = INT_MIN; 
    int n = arr.size(); 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            maxXor = max(maxXor, (arr[i] ^ arr[j])); 
            cout<<arr[i]<<" ^ "<<arr[j]<<": "<<(arr[i] ^ arr[j])<<endl; 
        }
    }

    return maxXor; 
}

int main(){
    int n; 
    cin>>n; 

    vector<int> arr(n); 
    for(int i = 0; i < n; i++)
        cin>>arr[i]; 

    cout<<findMaximumXOR(arr)<<endl; 

    return 0; 
}