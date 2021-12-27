// LC 36
// Valid Sudoku

#include<iostream>
#include<vector>
using namespace std; 

bool checkColumns(vector<vector<char>> &board){
    for(int i = 0; i < 9; ++i){
        vector<bool> table(10, false); 
        for(int j = 0; j < 9; ++j){
            if(board[j][i] != '.'){
                if(table[board[j][i] - '0']) return false;
                else table[board[j][i] - '0'] = true;
            } 
        }
    }

    return true;
}

bool checkRows(vector<vector<char>> &board){
    for(int i = 0; i < 9; ++i){
        vector<bool> table(10, false); 
        for(int j = 0; j < 9; ++j){
            if(board[i][j] != '.'){
                if(table[board[i][j] - '0']) return false;
                else table[board[i][j] - '0'] = true;
            }
        }
    }

    return true;
}

bool checkSubBoxes(vector<vector<char>> &board){
    for(int i = 0; i <= 6; i += 3){
        for(int j = 0 ; j <=  6; j += 3){
            vector<bool> table(10, false); 

            for(int x = 0; x < 3; ++x){
                for(int y = 0; y < 3; ++y){
                    if(board[i + x][j + y] != '.'){
                        if(table[board[i + x][j + y] - '0']) return false;
                        else table[board[i + x][j + y] - '0'] = true;
                    }
                }
            }
        }
    }

    return true; 
}

bool isValidSudoku(vector<vector<char>> &board){
    return checkColumns(board) && checkRows(board) && checkSubBoxes(board); 
}

int main(){
    vector<vector<char>> board(9, vector<char>(9));

    for(int i = 0; i < 9; ++i){
        string row; 
        cin>>row; 

        for(int j = 0; j < 9; ++j)
            board[i][j] = row[j];
    } 
    // cout<<"Hello"<<endl; 
    cout<<boolalpha<<isValidSudoku(board)<<endl; 

    return 0; 
}