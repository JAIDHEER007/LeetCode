// Runtime: 64ms
// Faster Than: 99.30%
// Memory Usage: 32.3Mb
// Less Than: 40.04%
// Expected Time Complexity: O(nlogn) + O(n) + O(nlogn) + O(n)
// Excpected Space Complexity: O(1)
// Algorithm Used: Greedy + Running Maximum
// int64_t datatype is used

#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;

int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
    sort(horizontalCuts.begin(), horizontalCuts.end()); 
    sort(verticalCuts.begin(), verticalCuts.end());


    // Start Value to get correct cut length; 
    int start = 0; 

    // Finding the maxVertical Cut
    int64_t maxVcut = INT_MIN;

    verticalCuts.push_back(w); 
    for(int cut:verticalCuts){
        maxVcut = max(maxVcut, int64_t(cut - start)); 
        start = cut; 
    }

    // Finding the maxHorizontal Cut
    int64_t maxHcut = INT_MIN;
    start = 0; 

    horizontalCuts.push_back(h); 
    for(int cut:horizontalCuts){
        maxHcut = max(maxHcut, int64_t(cut - start)); 
        start = cut; 
    }

    int mod = 1000000007; 
    return ((maxHcut % mod) * (maxVcut % mod)) % mod; 
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
        int h, w; 
        fin>>h>>w; 


        int hcCnt; fin>>hcCnt; 
        vector<int> hCuts(hcCnt); 
        for(int i = 0; i < hcCnt; ++i)
            fin>>hCuts[i]; 

        // for(int element:hCuts)
        //     cout<<element<<" "; 
        // cout<<endl; 

        int vcCnt; fin>>vcCnt; 
        vector<int> vCuts(vcCnt); 
        for(int i = 0; i < vcCnt; ++i)
            fin>>vCuts[i];

        // for(int element:vCuts)
        //     cout<<element<<" "; 
        // cout<<endl; 

         
        cout<<maxArea(h, w, hCuts, vCuts)<<endl; 
        
        // ===== END =====
    }
    
    return 0; 
}