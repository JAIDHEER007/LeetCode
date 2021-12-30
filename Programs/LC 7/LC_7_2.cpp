// runtime: 4 ms
// faster than: 39.07%

// memory usage: 5.9 mb
// less than: 75.27%

#include<iostream>
using namespace std; 

int reverse(int num){
    int rev = 0; 
    while(num){
        if(rev > (INT_MAX / 10) || rev < (INT_MIN / 10)) return 0; 
        rev = (rev * 10) + (num % 10); 
        num /= 10; 
    }

    return rev; 
}

int main(){
    int num; 
    cin>>num; 

    cout<<reverse(num)<<endl; 

    return 0; 
}