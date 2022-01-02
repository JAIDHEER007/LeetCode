// Brute Force

#include<iostream>
#include<vector>

using namespace std; 

int numPairsDivisibleBy60(vector<int> arr){
    int pairCount = 0; 

    for(int i = 0; i < arr.size() - 1; ++i){
        for(int j = i + 1; j < arr.size(); ++j)
            if((arr[i] + arr[j]) % 60 == 0) ++pairCount; 
    }
    return pairCount; 
}

int main(){
    int n; 
    cin>>n; 

    vector<int> arr(n); 
    for(int i = 0; i < n; ++i)
        cin >> arr[i]; 

    cout<<numPairsDivisibleBy60(arr)<<endl; 

    return 0; 
}
