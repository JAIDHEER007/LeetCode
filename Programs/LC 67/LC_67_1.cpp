// Using the extra space by padding with zeroes


// Runtime: 0ms
// Faster Than: 100.00%

// Memory Usage: 6.4 MB
// Less than: 58.13% 


#include<iostream>
using namespace std; 

string addBinary(string a, string b){
    // Adding the padding zeroes to make both the strings to equal length
    int a_len = a.length();
    int b_len = b.length(); 

    if(a_len < b_len){
        a = string((b_len - a_len), '0') + a; 
        a_len = b_len; 
    }
    else if(b_len < a_len){
        b = string((a_len - b_len), '0') + b;
        b_len = a_len; 
    }

    string result(a_len, ' '); 

    int carry = 0; 
    for(int i = a_len - 1; i >= 0; --i){
        int sum = ((a[i] - '0') + (b[i] - '0') + carry); 

        // Sum Bit
        result[i] = ((sum % 2) + '0'); 

        // Carry Bit
        carry = (sum / 2); 
    }

    // End Carry is Present
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