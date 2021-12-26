// LC 973
// K Closet Points to Origin

// Runtime: 264 ms
// Faster Than: 31.61%

// Memory Usage: 93.3MB
// Less Than: 8.06%

#include<iostream>
#include<vector>
#include<map>
#include<cmath>
using namespace std; 

float findDistOrg(vector<int> point){
    return sqrt((point[0] * point[0]) + (point[1] * point[1])); 
}

vector<vector<int>> kClosest(vector<vector<int>> points, int k){
    map<float, vector<vector<int>>> table; 

    for(int i = 0; i < points.size(); ++i){
        table[findDistOrg(points[i])].push_back(points[i]); 
    }

    vector<vector<int>> result; 
    for(auto it = table.begin(); it != table.end(); ++it){
        for(vector<int> point:it->second){
            if(k > 0){
                result.push_back(point); 
                --k; 
            }else return result; 
        }
    }

    return result; 
}

int main(){
    int n; cin>>n;

    vector<vector<int>> points(n, {0, 0});
    for(int i = 0; i < n; ++i)
        cin>>points[i][0]>>points[i][1]; 

    int k; cin>>k; 

    vector<vector<int>> result = kClosest(points, k); 

    for(vector<int> point:result)
        cout<<point[0]<<" "<<point[1]<<endl;  

    return 0; 
}