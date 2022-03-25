// Runtime: 28ms
// Faster Than: 97.77%
// Memory Usage: 21.2MB
// Less Than: 80.71%

#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

string getSmallestString(int n, int k){
    string result = string(n, 'a');
    // Result string

    for(int i = n - 1; i >= 0; --i){
        int diff = k - 26; 

        if(diff <= i){
            result[i] = char('a' + (k - i) - 1); 
            k = i; 
        }else{
            result[i] = 'z'; 
            k -= 26; 
        }
    }

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

        cout<<"======== TestCase "<<i<<" ========"<<endl;


        // Write input and output here
        // Instead of cin use fin

        // ===== START =====
        int n; fin>>n; 
        int k; fin>>k; 

        cout<<getSmallestString(n, k)<<endl;         
        // ===== END =====
    }
    
    return 0; 
}