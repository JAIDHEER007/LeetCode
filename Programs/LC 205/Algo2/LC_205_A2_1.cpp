#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<unordered_map>

using namespace std;

// Implement the solution class 
// With the given methods
class Solution {
public:
    vector<int> stringTransform(string s){
        int n = s.length();
        vector<int> transformArr(n); 

        unordered_map<char, int> umap; 
        for(int i = 0; i < n; i++){
            if(umap.find(s[i]) == umap.end())
                umap[s[i]] = i; 

            transformArr[i] = umap[s[i]]; 
        }

        return transformArr; 

    }
    bool isIsomorphic(string s, string t) {
        vector<int> transformS = stringTransform(s);
        vector<int> transformT = stringTransform(t); 

        int n = s.length(); 
        for(int i = 0; i < n; ++i){
            if(transformS[i] != transformT[i])
                return false; 
        }

        return true; 
    }
};

int main(){
    // change the number of test cases
    int nInputs = 5;

    // Creating a Solution Object
    Solution* solObj = new Solution(); 

    // test case files should be input1.txt, input2.txt, ..., inputN.txt format
    for(int i = 1; i <= nInputs; i++){
        string filename = "../input" + to_string(i) + ".txt"; 

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
        string t; fin>>t; 

        cout<<s<<endl; 
        cout<<t<<endl; 
        cout<<boolalpha<<(solObj->isIsomorphic(s, t))<<endl; 
        
        // ===== END =====
    }
    
    return 0; 
}