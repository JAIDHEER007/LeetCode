// Runtime: 0ms
// Faster Than: 100.00%
// Memory Usage: 6.7 mb
// Less Than: 64.08%

// Time Complexity: O(n)
// Space Complexity: O(1)

#include<iostream>
#include<fstream>
#include<vector>
#include<sstream> 

using namespace std;

vector<int> partitionLabels(string s){
    int n = s.length(); 

    vector<int> lastIndex(26, 0); 
    for(int i = 0; i < n; i++)
        lastIndex[s[i] - 'a'] = i; 

    vector<vector<int>> partitions; 

    int pStart = -1, pEnd = -1; 
    vector<int> partSizes; 
    for(int i = 0 ; i < n; i++){
        // if no partitions were created
        // Create one 
        if((pStart == -1) && (pEnd == -1)){
            pStart = 0; 
            pEnd = lastIndex[s[i] - 'a']; 
        }
        else{
            // Check if the firstIndex i.e 'i' lies within the last partition
            if((i >= pStart) && (i <= pEnd)){
                // First Index Lies inside the partiton
                // Check for the last index
                // If last Index is greator than lastPartiton's ending 
                // Then expand the lastPartiton
                pEnd = max(pEnd, lastIndex[s[i] - 'a']); 

            }else{
                // As First Index doesn't lie in the partition
                // We will create a new partition
                partSizes.push_back(pEnd - pStart + 1); 
                pStart = i; 
                pEnd = lastIndex[s[i] - 'a']; 
            }
        }
    }

    partSizes.push_back(pEnd - pStart + 1); 
    return partSizes; 
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
        string data; getline(fin, data); 

        vector<int> result = partitionLabels(data); 

        for(int element:result)
            cout<<element<<" "; 
        cout<<endl; 
        
        // ===== END =====
    }
    
    return 0; 
}