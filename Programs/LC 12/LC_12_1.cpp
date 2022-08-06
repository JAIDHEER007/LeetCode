#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<unordered_map>

using namespace std;

string intToRoman(int num) {
    unordered_map<int, char> umap; 

    umap[1] = 'I'; 
    umap[5] = 'V'; 
    umap[10] = 'X'; 
    umap[50] = 'L'; 
    umap[100] = 'C'; 
    umap[500] = 'D'; 
    umap[1000] = 'M'; 

    string result = ""; 

    int tens = 1; 

    while(num){
        int rem = num % 10; 

        string romanDigit = ""; 
        switch (rem){
            case 0: break; 
            case 4:
                romanDigit = (string(1, umap[tens]) + string(1, umap[5 * tens]));
                break; 
            case 9: 
                romanDigit = (string(1, umap[tens]) + string(1, umap[tens * 10]));
                break; 
            default:
                int centerPoint = (5 * tens); 
                if((rem * tens) < centerPoint){
                    // number is less than centerPoint
                    // repeat the starting tens 'rem' times
                    romanDigit = string(rem, umap[tens]); 
                }else{
                    // number is greator than centerPoint
                    // (rem - 5) tens to centerpoint
                    romanDigit = (umap[centerPoint] + string((rem - 5), umap[tens])); 
                }
        }

        result = romanDigit + result; 

        tens *= 10; 
        num /= 10;
        
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

        cout<<n<<endl; 
        cout<<intToRoman(n)<<endl;
        
        // ===== END =====
    }
    
    return 0; 
}