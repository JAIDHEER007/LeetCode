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
        bool isIsomorphic(string s, string t) {
            unordered_map<char, char> umap; 
            unordered_map<char, bool> mapped; 

            int n = s.length(); 
            for(int i = 0; i < n; ++i){
                if(!mapped[t[i]]){
                    if(umap.find(s[i]) != umap.end()) return false; 
                    umap[s[i]] = t[i];
                    mapped[t[i]] = true; 
                }else if(umap[s[i]] != t[i])
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