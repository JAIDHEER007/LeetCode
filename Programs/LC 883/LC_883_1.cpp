#include<iostream>
#include<vector>

using namespace std; 

int projectionArea(vector<vector<int>> &grid){
    int n = grid[0].size(); 

    int xyArea = 0;
    int yzArea = 0; 
    int xzArea = 0;
    for(int i = 0; i < n; i++){
        int maxHeight1 = INT_MIN;
        int maxHeight2 = INT_MIN; 
        for(int j = 0; j < n; ++j){
            if(grid[i][j] > 0) ++xyArea; 
            maxHeight1 = max(maxHeight1, grid[i][j]); 
            maxHeight2 = max(maxHeight2, grid[j][i]); 
        }
        yzArea += maxHeight1;
        xzArea += maxHeight2; 
    }

    return xyArea + yzArea + xzArea; 
}

int main(){
    int n; 
    cin>>n; 

    vector<vector<int>> grid(n, vector<int>(n)); 

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cin>>grid[i][j]; 
    }

    cout<<projectionArea(grid)<<endl; 

    return 0; 
}