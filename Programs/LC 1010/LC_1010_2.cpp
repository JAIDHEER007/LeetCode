// Runtime: 35 ms
// Faster than: 39.37%
// Memory Usage: 23.2 mb
// less than: 60.38%

#include<iostream>
#include<vector>

using namespace std; 

int numPairsDivisibleBy60(vector<int> arr){
    vector<int> hashTable(60, 0); 

    for(int i = 0; i < arr.size(); ++i)
        ++hashTable[arr[i] % 60]; 

    int pairCount = 0; 
    
    // Adding elements which are perfectly divisible by 60
    // i.e x % 60 == 0
    pairCount += (hashTable[0] * (hashTable[0] - 1)) / 2; 

    // Adding 30
    // 30 % 60 == 30 and 60 - 30 = 30 
    // Self Looping
    pairCount += (hashTable[30] * (hashTable[30] - 1)) / 2;


    // Starting i from 1 to 29
    // Adding them pairCount
    // Number of pairs will be (ht[i] * ht[60 - i])
    for(int i = 1; i < 30; ++i)
        pairCount += (hashTable[i] * hashTable[60 - i]); 

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
