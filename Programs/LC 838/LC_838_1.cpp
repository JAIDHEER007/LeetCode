// Time Limit Exceeded 
// Passed 32 out of 43 cases
// Time Complexity; O(n^3)
// Space Complexity: O(n)

#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>

using namespace std;

// Implement the solution class 
// With the given methods
class Solution {
    public:
        int giveLDst(string dominoes, int i){
            int steps = 0; 

            for(int n = dominoes.length();i < n; ++i, ++steps){
                if(dominoes[i] == 'L')
                    return steps - 1; 
                else if(dominoes[i] == 'R')
                    return INT_MAX; 
            }

            return INT_MAX; 
        }

        int giveRDst(string dominoes, int i){
            int steps = 0; 

            for(; i>= 0; --i, ++steps){
                if(dominoes[i] == 'R')
                    return steps - 1; 
                else if(dominoes[i] == 'L')
                    return INT_MAX; 
            }

            return INT_MAX; 
        }

        string pushDominoes(string dominoes) {
            int n = dominoes.length();  
            string result = string(n, ' ');
            for(int i = 0; i < n; ++i){
                if(dominoes[i] == '.'){
                    int LDst = giveLDst(dominoes, i); 
                    int RDst = giveRDst(dominoes, i); 

                    result[i] = ((LDst == RDst)?('.'):((LDst > RDst)?('R'):('L'))); 
                }else
                    result[i] = dominoes[i]; 
            }

            return result; 
        }
};

int main(){
    // change the number of test cases
    int nInputs = 8;

    // Creating a Solution Object
    Solution *solObj = new Solution(); 

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
        string dominoes; fin>>dominoes; 
        cout<<dominoes<<endl; 
        cout<<(solObj->pushDominoes(dominoes))<<endl; 
        
        // ===== END =====
    }
    
    return 0; 
}