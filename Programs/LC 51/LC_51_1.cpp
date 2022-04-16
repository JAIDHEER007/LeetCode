

#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>

using namespace std;

bool isValid(int i, int j, int n){
    return (((i >= 0) && (i < n)) && ((j >= 0) && (j < n))); 
}

void dfs(vector<vector<string>> &result, int &n, 
        vector<string> grid, vector<vector<bool>> colsAllowed, 
        int row){

    // Base Case
    if(row == n){
        // All the rows were traversed
        // this is a possible solution
        // Add it to the result
        result.push_back(grid); 

        return; 
    }

    // Iterative Case
    // check if any column is allowed 
    for(int i = 0; i < n; i++){
        if(colsAllowed[row][i]){
            // Now chose this possition

            // Place a Queen in this possition
            grid[row][i] = 'Q'; 
        
            // Copy the colsAllowed grid to a new one
            vector<vector<bool>> temp; 
            temp.assign(colsAllowed.begin(), colsAllowed.end());

            // Make the path of queen to false to avoid the placement of future queens

            // Straight down 
            for(int k = 0; isValid((row + k), i, n); ++k)
                temp[row + k][i] = false; 

            // left diagonallly down 
            for(int k = 0; isValid((row + k), (i - k), n); ++k)
                temp[row + k][i - k] = false; 

            // right diagonally down 
            for(int k = 0; isValid((row + k), (i + k), n); ++k)
                temp[row + k][i + k] = false;

            // Check for the next queen
            dfs(result, n, grid, temp, (row + 1));  

            // Reset the Prev Queen position
            grid[row][i] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<string> grid(n, string(n, '.')); 

    vector<vector<bool>> colsAllowed(n, vector<bool>(n, true)); 
    vector<vector<string>> result; 

    dfs(result, n, grid, colsAllowed, 0); 

    return result; 
}

int main(){
    // change the number of test cases
    int nInputs = 5;

    // test case files should be input1.txt, input2.txt, ..., inputN.txt format
    for(int i = 1; i <= nInputs; i++){
        string filename = "input" + to_string(i) + ".txt"; 

        ifstream fin(filename); 
        if(!fin.is_open()){
            cout<<"Cannot Open the test case"<<endl;
            return 0; 
        }

        cout<<"================= TestCase "<<i<<" ================="<<endl;


        // Write input and output here
        // Instead of cin use fin

        // ===== START =====
        int n; fin>>n; 

        vector<vector<string>> result = solveNQueens(n); 

        for(int i = 0; i < result.size(); ++i){
            cout<<"=============== "<<(i + 1)<<" ==============="<<endl; 
            for(string row:result[i])
                cout<<row<<endl; 
        }
        // ===== END =====
    }
    
    return 0; 
}