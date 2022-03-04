// Using only 2 arrays 
// Yet to be implemented

#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

double champagneTower(int poured, int query_row, int query_glass) {
    vector<vector<double>> arr(2, vector<double>(100, 0.0)); 

    arr[0][0] = poured;  
    int i, j; 

    for(i = 0; i < query_row; ++i){
        for(j = 0; j < (i + 1); ++j){ 
            if(arr[i & 1][j] > 1.0f){
                double remaining = arr[i & 1][j] - 1.0f; 
                arr[(i + 1) & 1][j] += (remaining / 2.0f); 
                arr[(i + 1) & 1][j + 1] += (remaining / 2.0f); 
                arr[i & 1][j] = 0.0; 
            }
        }
    }
    --j; 
    while(j >= 0) arr[(i - 1) & 1][j--] = 1.0; 
    
    double result = arr[query_row & 1][query_glass]; 
    return min(result, 1.0); 
}

int main(){
    // change the number of test cases
    int nInputs = 7;

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
