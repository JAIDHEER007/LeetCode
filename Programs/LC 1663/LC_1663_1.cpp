#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

string getSmallestString(int n, int k){
    string result = ""; 
    // Result string

    for(int i = 1; i <= n; i++){
        int diff = k - 26; 
        // Let's greedily chose 'z' 
        // 'diff' holds remaining numeric value that needs to be achieved

        if(diff <= (n - i)){
            // if diff is less than or equal to remining (n - i) elements
            // Then we cannot use 'z' in our result string
            // As the 'diff' numeric value cannot be shared ammong the remaining elements
            // So we cannot use 'z' but any charcater less than 'z' in our result

            // If we subtract 26 from 'k' we cannot satisfy the remianing n - i elements
            // So we should remove less than 26 from k
            // Why dont we subtract (n - i) from 'k' so that All the remaining (n - i) elements can be satisfied
            // Therefore we should add alphabet represented by (k - (n - i)) in 1 based indexing
            // Now the target numeric value will be 'n - i'
            
            // Let 'x' be the alphabet position in 1 based indexing
            // Then we can get the charcater using
            // char('a' + x - 1)

            result += char('a' + (k - (n - i)) - 1); 
            k = (n - i); 
        }else{
            // if diff is greator than the reminaing (n - i) elements 
            // We can chose to use 'z' in our string
            // Now the target numeric value will be reduced by 26
            result += 'z'; 
            k -= 26; 
        }
    }

    reverse(result.begin(), result.end()); 
    return result; 
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
        int n; fin>>n; 
        int k; fin>>k; 

        cout<<getSmallestString(n, k)<<endl;         
        // ===== END =====
    }
    
    return 0; 
}