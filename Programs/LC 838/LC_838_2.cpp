// Time Limit Exceeded 
// Passed 37 out of 43 cases
// Time Complexity; O(n^2)
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
            for(int n = dominoes.length();i < n; ++i){
                if(dominoes[i] == 'L')
                    return i; 
                else if(dominoes[i] == 'R')
                    return -1; 
            }

            return -1; 
        }

        string pushDominoes(string dominoes) {
            int n = dominoes.length();  
            string result = dominoes;

            int Rindex = -1; 
            int Lindex = giveLDst(dominoes, 0); 

            for(int i = 0; i < n; ++i){
                if(dominoes[i] == 'R'){
                    Rindex = i; 
                    Lindex = giveLDst(dominoes, i + 1); 
                }else if(dominoes[i] == 'L'){
                    Lindex = giveLDst(dominoes, i + 1); 
                    Rindex = -1; 
                }else{
                    if((Lindex == -1) && (Rindex != -1)){
                        result[i] = 'R'; 
                    }else if((Lindex != -1) && (Rindex == -1)){
                        result[i] = 'L';
                    }else{
                        int LDst = abs(i - Lindex); 
                        int RDst = abs(i - Rindex); 

                        result[i] = ((LDst == RDst)?('.'):((LDst > RDst)?('R'):('L'))); 
                    }
                    
                }
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