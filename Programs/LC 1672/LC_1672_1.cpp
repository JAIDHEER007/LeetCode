#include<iostream>
#include<vector>
using namespace std; 

int maximumWealth(vector<vector<int>> arr){
    int maxWealth = INT_MIN; 

    for(int i = 0; i < arr.size(); i++){
        int sum = 0; 
        for(int j = 0; j < arr[i].size(); sum += arr[i][j], ++j); 
        maxWealth = max(maxWealth, sum); 
    }

    return maxWealth; 
}

int main(){
    int n, m; 
    cin>>n>>m;

    vector<vector<int>> arr(n, vector<int>(m, 0)); 

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cin>>arr[i][j]; 
    }

    cout<<maximumWealth(arr)<<endl; 

    return 0; 
}