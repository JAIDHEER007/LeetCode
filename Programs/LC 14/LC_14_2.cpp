// Divide and Conquer

#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>

using namespace std;

class Solution {
    private:
        string findprefix(string s1, string s2){
            string prefix = "";
            int len = min(s1.length(), s2.length());
                    
            for(int i = 0; i < len; ++i){
                if(s1[i] != s2[i]) break;
                prefix += s1[i]; 
            }
            
            return prefix; 
        }

        string divide(vector<string> &strs, int start, int end){
            if(start == end)
                return strs[start]; 
            

            int mid = (start + end) >> 1; 
            string leftPrefix = divide(strs, start, mid); 
            string rightPrefix = divide(strs, mid + 1, end); 

            return findprefix(leftPrefix, rightPrefix); 
        }

    public:
        string longestCommonPrefix(vector<string>& strs) {
            if(strs.size() == 1)
                return strs[0]; 
            
            return divide(strs, 0, strs.size() - 1); 
        }
};

int main(){
    // change the number of test cases
    int nInputs = 5;

    // Creating a Solution Object
    Solution* solObj = new Solution(); 

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
        string rawData;
        getline(fin, rawData); 

        // Tokenize the given string
        vector<string> strs; 
        string token = "";
        for(int i = 0; i < rawData.length(); ++i){
            if(rawData[i] == ','){
                strs.push_back(token); 
                token = "";
            }else{
                if(rawData[i] >= 'a' && rawData[i] <= 'z') 
                    token += rawData[i]; 
            }
        }strs.push_back(token);
         

        cout<<(solObj->longestCommonPrefix(strs))<<endl; 
        
        // ===== END =====
    }
    
    return 0; 
}