// Runtime: 12 ms
// Faster than: 61.01 %
// Memory Usage: 17.6 mb
// Less Than: 32.66 % 

#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

double champagneTower(int poured, int query_row, int query_glass) {
    int n = query_row + 2; 
    vector<vector<double>> arr(n, vector<double>(100, 0.0)); 

    arr[0][0] = poured; 
    for(int i = 0; i < n-1; ++i){
        for(int j = 0; j < (i + 1); ++j){
            if(arr[i][j] > 1.0f){
                double remaining = arr[i][j] - 1.0f; 
                arr[i + 1][j] += (remaining / 2.0f); 
                arr[i + 1][j + 1] += (remaining / 2.0f); 
                arr[i][j] = 1.00; 
            }
        }
    }
    return arr[query_row][query_glass];
}

int main(){
    // change the number of test cases
    int nInputs = 4;

    // test case files should be input1.txt, input2.txt, ..., inputN.txt format
    for(int i = 1; i <= nInputs; i++){
        string filename = "input" + to_string(i) + ".txt"; 

        ifstream fin(filename); 
        if(!fin.is_open()){
            cout<<"Cannot Open the test case"<<endl;
            return 0; 
        }

        cout<<"======== TestCase "<<i<<" ========"<<endl;


        // Write input and output here
        // Instead of cin use fin

        // ===== START =====
        int poured, query_row, query_glass; 
        fin>>poured>>query_row>>query_glass; 

        cout<<champagneTower(poured, query_row, query_glass)<<endl; 

        // ===== END =====
    }
    
    return 0; 
}
