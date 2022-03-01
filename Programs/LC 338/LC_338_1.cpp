// Time Complexity: O(nlog₁₀n)

#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int setBits(int num){
    int count = 0;
    while(num){
        count += (num & 1);
        num >>= 1;
    }
    return count;
}

vector<int> countBits(int n) {
    vector<int> result;
    for(int i=0;i<=n;i++)
        result.push_back(setBits(i));
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
        vector<int> results = countBits(n); 

        for(int result:results)
            cout<<result<<" "; 
        cout<<endl; 

        // ===== END =====
    }
    
    return 0; 
}