// Pretty much it doesn't work
// The result set will contain duplicate sets

#include<iostream>
#include<vector>

using namespace std; 

vector<vector<int>> threeSum(vector<int> arr){
    vector<vector<int>> result; 
    int n = arr.size(); 
    
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                if(arr[i] + arr[j] + arr[k] == 0) 
                    result.push_back({arr[i], arr[j], arr[k]}); 
            }
        }
    }

    return result; 
}

int main(){
    int n; 
    cin>>n; 

    vector<int> arr(n); 
    for(int i = 0; i < n; i++)
        cin>>arr[i]; 

    vector<vector<int>> result = threeSum(arr); 

    for(vector<int> row:result){
        for(int element:row)
            cout<<element<<" "; 
        cout<<endl; 
    }

    return 0; 
}