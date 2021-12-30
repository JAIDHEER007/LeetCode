#include<iostream>
using namespace std; 

int myAtoi(string num){
    int number = 0; 

    for(int i = 0; i < num.length(); ++i)
        number = (number * 10) + (num[i] - '0'); 

    return number; 
}

int main(){
    string num; 
    cin>>num; 

    cout<<myAtoi(num)<<endl; 

    return 0; 
}