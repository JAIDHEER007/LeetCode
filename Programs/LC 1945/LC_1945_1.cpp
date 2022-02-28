#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int getLucky(string s, int k){
    int sum = 0; 
    for(int i = 0; i < s.length(); i++){
        int number = (s[i] - 'a' + 1); 
        while(number){
            sum += (number % 10); 
            number /= 10; 
        }
    }

    for(int i = 1; i < k; i++){
        int number = sum; 
        sum = 0; 
        while(number){
            sum += (number % 10); 
            number /= 10; 
        }
    }

    return sum; 
}

int main(){
    // change the number of test cases
    int nInputs = 3;

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
        string s; fin >> s; 
        int k; fin>>k; 

        cout<<getLucky(s, k)<<endl; 
        
        // ===== END =====
    }
    
    return 0; 
}