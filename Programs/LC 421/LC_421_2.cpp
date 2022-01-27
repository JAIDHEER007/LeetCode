#include<iostream>
#include<vector>

using namespace std; 

int main(){
    int n; cin>>n; 

    vector<int> arr(n); 
    for(int i = 0; i < n; i++)
        cin>>arr[i]; 

    int index; 
    cin>>index; 

    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ^ "<<arr[index]<<": "<<(arr[i] ^ arr[index])<<endl; 

    return 0; 
}