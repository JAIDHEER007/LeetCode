// Returns a integer result

#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int mySqrt(int x){
    int start = 1; 
    int end = x; 
    
    while(start < end){
        long mid = end + (start - end) / 2; 
 
        if((mid * mid) == x)
            return mid; 
        if(mid <= (x / mid))
            start = mid + 1; 
        else 
            end = mid - 1; 
    }

    return end; 

}

int main(){
    // change the number of test cases
    int nInputs = 5;

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
        cout<<mySqrt(x)<<endl; 
        
        // ===== END =====
    }
    
    return 0; 
}