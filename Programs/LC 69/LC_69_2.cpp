// Returns a floating result

#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

double mySqrt(int x, double precision){
    int start = 0; 
    int end = x; 
    double result;
    while(start < end){
        double mid = end + (start - end) / 2; 
 
        if((mid * mid) - (double)x == precision)
            return mid; 
        if(mid <= (x / mid)){
            result = mid; 
            start = mid + 1; 
        }
        else 
            end = mid - 1; 
    }

    return result; 

}

int main(){
    // change the number of test cases
    int nInputs = 5;
    double precision = 10e-5;

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
        int x; fin >> x; 
        cout<<mySqrt(x, precision)<<endl; 
        
        // ===== END =====
    }
    
    return 0; 
}