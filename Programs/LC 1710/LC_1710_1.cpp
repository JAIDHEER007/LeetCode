// Runtime: 414 ms
// Faster Than: 5.47%
// Memory Usage: 49.4 Mb
// Less Than: 14.24%

// Expected Time Complexity: O(nlogn) + O(n) 
// Expected Space Complexity: O(1)

#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<sstream>

using namespace std;

int maximumUnits(vector<vector<int>> &boxTypes, int truckSize){
    int totalUnits = 0; 
    
    sort(boxTypes.begin(), boxTypes.end(), 
        [](vector<int> a, vector<int> b){
            return a[1] > b[1]; 
        });

    // for(vector<int> box:boxTypes){
    //     for(int element:box)
    //         cout<<element<<" "; 
    //     cout<<endl; 
    // }

    int n = boxTypes.size(); 
    for(int i = 0 ; i < n && truckSize; ++i){
        int unitsChosen = boxTypes[i][1]; 
        int boxChosen = min(boxTypes[i][0], truckSize); 
        truckSize -= boxChosen; 

        totalUnits += (boxChosen * unitsChosen); 
    }

    return totalUnits; 
}

int main(){
    // change the number of test cases
    int nInputs = 2;

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
        vector<vector<int>> boxTypes(n, vector<int>(2)); 

        for(int i = 0 ; i < n; ++i)
            fin>>boxTypes[i][0]>>boxTypes[i][1]; 
        
        int truckSize; fin>>truckSize; 

        cout<<maximumUnits(boxTypes, truckSize)<<endl; 
        
        // ===== END =====
    }
    
    return 0; 
}