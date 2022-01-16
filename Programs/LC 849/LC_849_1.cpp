// Runtime: 8ms
// Faster Than: 96.68%

// Memory Usage: 17.5 MB
// Less Than: 23.58%

#include<iostream>
#include<vector>

using namespace std; 

int maxDistToClosest(vector<int> arr){
    int n = arr.size(); 

    // Distance to first one
    int dist_f1 = 0; 
    bool f1_found = false; 

    int dist_2_ones = 0; 
    int max_dist_2_ones = 0; 

    for(int i = 0; i < n; ++i){
        // Finding the distance to first one
        if(!f1_found){
            if(arr[i] == 1)
                f1_found = true; 
            else
                ++dist_f1; 
        }

        if(arr[i] == 0 && (f1_found)) ++dist_2_ones; 
        else{
            max_dist_2_ones = max(max_dist_2_ones, dist_2_ones + 1); 
            dist_2_ones = 0; 
        }
    }

    if(((max_dist_2_ones >> 1) >= dist_f1) && ((max_dist_2_ones >> 1) >= dist_2_ones))
        return (max_dist_2_ones >> 1); 
    return max(dist_f1, dist_2_ones); 
}

int main(){
    int n; 
    cin>>n; 

    vector<int> arr(n); 
    for(int i = 0; i < n; ++i)
        cin>>arr[i]; 
    
    cout<<maxDistToClosest(arr)<<endl; 

    return 0; 
}