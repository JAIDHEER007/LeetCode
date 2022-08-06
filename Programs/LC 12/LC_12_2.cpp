#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>

using namespace std;

string intToRoman(int num) {
    int numbers[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}; 
    string romanNumerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}; 

    string result = "";
    for(int i = 0; i < 13; i++){
        while(num >= numbers[i]){
            result += romanNumerals[i]; 
            num -= numbers[i]; 
        }
    }

    return result; 
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

        cout<<intToRoman(n)<<endl; 
        
        // ===== END =====
    }
    
    return 0; 
}