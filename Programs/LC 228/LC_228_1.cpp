#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

vector<string> summaryRanges(vector<int> nums){
    vector<string> ranges;

    int prevIndex = 0; 
    int nextIndex = 0; 
    
    int n = nums.size(); 

    if(n == 0) return {};

    for(int i = 1; i < n; i++){
        // if((nums[i] - nums[i -1]) == 1)
        if(nums[i] == 1 + nums[i - 1])
            ++nextIndex; 
        else{
            if(prevIndex == nextIndex) 
                ranges.push_back(to_string(nums[prevIndex])); 
            else    
                ranges.push_back(to_string(nums[prevIndex]) + "->" + to_string(nums[nextIndex]));
            ++nextIndex; 
            prevIndex = nextIndex; 
        }
    }
    if(prevIndex == nextIndex) 
        ranges.push_back(to_string(nums[prevIndex])); 
    else    
        ranges.push_back(to_string(nums[prevIndex]) + "->" + to_string(nums[nextIndex]));

    return ranges;
}

int main(){
    // change the number of test cases
    int nInputs = 6;

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
            fin>>nums[i]; 
        
        vector<string> results = summaryRanges(nums); 
    
        for(string result:results)
            cout<<result<<endl; 
        
        // ===== END =====
    }
    
    return 0; 
}