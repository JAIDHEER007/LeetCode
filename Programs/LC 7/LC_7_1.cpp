// runtime: 4 ms
// faster than: 39.07%

// memory usage: 5.9 mb
// less than: 75.27%

#include<iostream>
using namespace std; 

int reverse(int num){
    if(num == INT_MIN || num == INT_MAX) return 0;

    bool isNegative = (num < 0); 
    if(isNegative) num = num * (-1); 

    int rev = 0; 
    while(num){
        if(rev > (INT_MAX / 10)) return 0; 
        rev = (rev * 10) + (num % 10); 
        num /= 10; 
    }

    return (isNegative)?(-1 * rev):(rev); 
}

int main(){
    int num; 
    cin>>num; 

    cout<<reverse(num)<<endl; 

    return 0; 
}