// Without padding zeroes

// Runtime: 3ms
// Faster Than: 72.69%

// Memory Usage: 7 MB
// Less than: 13.14% 


#include<iostream>
using namespace std; 

string addBinary(string a, string b){
    int a_len = a.length(); 
    int b_len = b.length(); 

    // Create empty result String
    string result; 

    int i = a_len - 1; 
    int j = b_len - 1; 

    int carry = 0; 
    while((i >= 0) && (j >= 0)){
        int sum = ((a[i] - '0') + (b[j] - '0') + carry);

        // Sum Bit
        result = to_string(sum % 2) + result; 
 
        // Carry Bit
        carry = (sum / 2); 

        // Decrement both i, j
        --i; 
        --j;  
    } 
    // Checking for any remaining input
    while(i >= 0){
        int sum = ((a[i] - '0') + carry);
        result = to_string(sum % 2) + result; 
        carry = (sum / 2); 
        --i; 
    }
    while(j >= 0){
        int sum = ((b[j] - '0') + carry);
        result = to_string(sum % 2) + result; 
        carry = (sum / 2); 
        --j; 
    }
    if(carry) result = to_string(carry) + result; 

    return result; 
}

int main(){
    string a; 
    cin>>a; 

    string b; 
    cin>>b; 

    cout<<addBinary(a, b)<<endl; 

    return 0; 
}