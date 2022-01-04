#include<iostream>
using namespace std; 

int bitwiseComplement(int num) {
    if(num == 0) return 1; 

    int result = 0; 
    int i = 0;
    while(num){
        int bit = (num % 2) ^ 1; 
        result += (bit * (1 << i));

        num /= 2; 
        ++i; 
    }

    return result;
}

int main(){
    int num; 
    cin>>num; 

    cout<<bitwiseComplement(num)<<endl; 

    return 0; 
}