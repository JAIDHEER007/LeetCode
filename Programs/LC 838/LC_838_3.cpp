#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>

using namespace std;

// Implement the solution class 
// With the given methods
class Solution {
    public:
        string pushDominoes(string dominoes) {
            int n = dominoes.length();  
            string result = dominoes;

            vector<int> rightForce(n + 1);
            vector<int> leftForce(n + 1);

            for(int i = 0; i < n; ++i){
                if(dominoes[i] == 'R')
                    rightForce[i + 1] = n; 
                else if(dominoes[i] == 'L')
                    rightForce[i + 1] = 0; 
                else
                    rightForce[i + 1] = (rightForce[i])?(rightForce[i] - 1):0;
            } 

            for(int i = n - 1; i >= 0; --i){
                if(dominoes[i] == 'L')
                    leftForce[i] = n; 
                else if(dominoes[i] == 'R')
                    leftForce[i] = 0; 
                else
                    leftForce[i] = (leftForce[i + 1])?(leftForce[i + 1] - 1):0;
            } 

            for(int i = 0; i < n; ++i){
                int LDst = leftForce[i];
                int RDst = rightForce[i + 1]; 

                result[i] = ((LDst == RDst)?('.'):((LDst > RDst)?('L'):('R')));
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