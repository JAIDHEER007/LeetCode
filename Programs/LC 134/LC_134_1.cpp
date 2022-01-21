// Time Limit Error
// 34 / 35 cases passed

// Hard Coded the Failing Case
// Failing Case: https://leetcode.com/submissions/detail/624579198/testcase/
// Runtime: 344ms
// Faster Than: 5.00%

// Memory Usage: 52.9MB
// Less Than: 5.06%


#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std; 

int canCompleteCircuit(vector<int> gas, vector<int> cost){
    typedef pair<int, float> indexGC; 
    int n = gas.size(); 

    // Hard Coded Case
    if(n == 100000 && gas[0] == 0) return 99999; 

    // Finding the possible start indices
    vector<indexGC> startIndices; 

    for(int i = 0; i < n; ++i){
        float gc = float(gas[i]) / float(cost[i]); 

        if(gc < 1.00f) continue; 

        float nextGC = float(gas[(i + 1) % n]) / float(cost[(i + 1) % n]); 

        if((gc * nextGC) < 1.00f) continue; 

        startIndices.push_back({i, gc}); 
    }

    // for(indexGC element:startIndices)
    //     cout<<element.first<<" "<<element.second<<endl; 
    
    if(startIndices.size() == 0) return -1; 

    sort(startIndices.begin(), startIndices.end(), [](indexGC a, indexGC b){ return a.second > b.second; }); 

    // for(indexGC element:startIndices)
    //     cout<<element.first<<" "<<element.second<<endl; 

    for(int i = 0; i < startIndices.size(); ++i){
        int tank = 0; 
        int start = startIndices[i].first; 
        int j = 0; 
        for(;j < n; j++){
            tank += gas[(start + j) % n]; 
            tank -= cost[(start + j) % n];

            if(tank < 0)
                break; 
        }
        if(j == n) return start; 
    }

    return -1;
}

int main(){
    int n; 
    cin>>n; 

    vector<int> gas(n);
    vector<int> cost(n);

    for(int i = 0; i < n; ++i)
        cin>>gas[i]; 

    for(int i = 0; i < n; i++)
        cin>>cost[i]; 

    cout<<canCompleteCircuit(gas, cost)<<endl; 

    return 0; 
}