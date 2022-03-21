// Runtime: 3ms
// Faster Than: 85.07%
// Memory Usage: 7 MB
// Less Than: 10.11%

// Time Complexity: O(n)
// Space Complexity: O(n)

#include<iostream>
#include<fstream>
#include<vector>
#include<unordered_map>
#include<sstream> 

using namespace std;

vector<int> partitionLabels(string s){
    int n = s.length(); 
    unordered_map<char, int> lastIndex; 

    for(int i = 0; i < n; i++)
        lastIndex[s[i]] = i; 

    vector<vector<int>> partitions; 

    for(int i = 0 ; i < n; i++){
        // if no partitions were created
        // Create one 
        if(partitions.size() == 0)
            partitions.push_back({0, lastIndex[s[i]]});
        else{
            // Some Partitions were created
            int endIndex = partitions.size() - 1; 

            // Check if the firstIndex i.e 'i' lies within the last partition
            if((i >= partitions[endIndex][0]) && (i <= partitions[endIndex][1])){
                // First Index Lies inside the partiton
                // Check for the last index
                // If last Index is greator than lastPartiton's ending 
                // Then expand the lastPartiton
                partitions[endIndex][1] = max(partitions[endIndex][1], lastIndex[s[i]]); 

            }else{
                // As First Index doesn't lie in the partition
                // We will create a new partition
                partitions.push_back({i, lastIndex[s[i]]});
            }
        }
    }

    vector<int> partSizes; 

    for(int i = 0 ; i < partitions.size(); i++)
        partSizes.push_back(partitions[i][1] - partitions[i][0] + 1);

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