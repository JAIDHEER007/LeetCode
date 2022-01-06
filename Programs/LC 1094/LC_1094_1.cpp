#include<iostream>
#include<vector>

using namespace std; 

bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<int> arr(10001, 0);
    
    for(int i = 0; i < trips.size(); ++i){
        for(int j = trips[i][1]; j < trips[i][2]; ++j)
            arr[j] += trips[i][0]; 
    }
    
    for(int i = 0; i < 1000; ++i)
        if(arr[i] > capacity) return false; 
    return true; 
}

int main(){
    int tripsN; 
    cin>>tripsN; 

    vector<vector<int>> trips(tripsN, vector<int>(3, 0)); 

    for(int i = 0; i < tripsN; ++i)
        cin>>trips[i][0]>>trips[i][1]>>trips[i][2]; 

    int capacity; 
    cin>>capacity; 

    cout<<boolalpha<<carPooling(trips, capacity)<<endl; 

    return 0; 
}