#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int arraySign(vector<int> nums){
    int zeroCount = 0; 
    int negativeCount = 0; 
    int n = nums.size(); 

    for(int i = 0; i < n; i++){
        if(nums[i] == 0) 
            ++zeroCount; 
        else if (nums[i] < 0)
            ++negativeCount; 
        if(zeroCount > 0) return 0; 
    }

    if((negativeCount == 0) || !(negativeCount & 1)) return 1; 
    return -1; 
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
        vector<int> nums(n); 
        for(int i = 0; i < n; i++)
            fin >> nums[i]; 

        cout<<arraySign(nums)<<endl; 
        
        // ===== END =====
    }
    
    return 0; 
}