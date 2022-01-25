// Runtime: 256ms
// Faster Than: 16.86%
// Memory Usage: 10.5 MB
// Less Than: 50.29%
// Time Complexity: O(n⁴)


#include<iostream>
#include<vector>
using namespace std; 

int countQuadruplets(vector<int> arr){
    int count = 0; 
    int n = arr.size(); 
    for(int a = 0; a < n; a++){
        for(int b = (a + 1); b < n; b++){
            for(int c = (b + 1); c < n; ++c){
                for(int d = (c + 1); d < n; ++d){
                    if((arr[a] + arr[b] + arr[c]) == arr[d])
                        ++count; 
                }
            }
        }
    }

    return count; 
}

int main(){
    int n; 
    cin>>n; 

    vector<int> arr(n); 
    for(int i = 0; i < n; i++)
        cin>>arr[i]; 
    
    cout<<countQuadruplets(arr)<<endl; 

    return 0; 
}