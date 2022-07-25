#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>

using namespace std;

static int NeedForSpeed = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

string convert(string s, int numRows){
    if(numRows == 1) return s; 

    vector<string> rows(numRows); 

    bool increasing = true; 
    int rowNum = 1; 

    int n = s.length(); 
    for(int i = 0; i < n; i++){
        if(rowNum == 1) increasing = true; 
        else if(rowNum == numRows) increasing = false; 

        rows[rowNum - 1] += s[i];
        rowNum = (increasing)?(rowNum + 1):(rowNum - 1); 
    }

    string res = ""; 
    for(int i = 0; i < numRows; ++i)
        res += rows[i]; 
    

    return res; 
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

        cout<<"======== TestCase "<<i<<" ========"<<endl;


        // Write input and output here
        // Instead of cin use fin

        // ===== START =====
        string s; fin>>s; 
        int numRows; fin>>numRows; 

        cout<<convert(s, numRows)<<endl; 
        
        // ===== END =====
    }
    
    return 0; 
}