#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

double champagneTower(int poured, int query_row, int query_glass) {
    vector<vector<double>> arr(100, vector<double>(100, 0.0f)); 

    arr[0][0] = poured; 
    for(int i = 0; i < 99; ++i){
        for(int j = 0; j < 99; ++j){
            if(arr[i][j] == 1e-9)
                break; 
            double remaining = arr[i][j] - 1.0f; 
            if(arr[i][j] > 1.0f){
                arr[i + 1][j] += double(remaining / 2.0f); 
                arr[i + 1][j + 1] += double(remaining / 2.0f); 
            }
        }
    }
    return ((arr[query_row][query_glass] > 1)?(1):(arr[query_row][query_glass]));
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
