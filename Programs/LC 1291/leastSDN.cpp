// Program to find the next least SDN given a non SDN number

#include<iostream>
#include<vector>

using namespace std; 

int numberLength(int number){
    int len = 0; 
    while(number){
        ++len; 
        number /= 10; 
    }

    return len; 
}

int nextSDN(int sdnNumber){
    int len = numberLength(sdnNumber); 
    int nextSdn = 0; 
    if(sdnNumber % 10 == 9){
        if(len == 9) return sdnNumber; 
        for(int i = 0; i <= len; i++)
            nextSdn = (nextSdn * 10) + ((nextSdn % 10) + 1); 
    }else{
        int ones = 0; 
        int bin = (1 << len) - 1; 
        while(bin){
            ones = (ones * 10) + 1;
            bin /= 2; 
        }
        nextSdn = sdnNumber + ones;
    }

    return nextSdn; 
}

int nextLeastSDN(int number){
    int len = numberLength(number); 
    int nextLeastSdn = 0; 
    for(int i = 0; i < len; i++)
            nextLeastSdn = (nextLeastSdn * 10) + ((nextLeastSdn % 10) + 1); 
    while(nextLeastSdn < number) nextLeastSdn = nextSDN(nextLeastSdn); 
    return nextLeastSdn;    
}

int main(){
    vector<int> numbers{1000, 1200, 1230, 1234,
                       10, 11, 13, 22, 25, 29,
                       6789, 6978}; 

    for(int i = 0; i < numbers.size(); ++i)
        cout<<"Number: "<<numbers[i]<<" Next Least SDN: "<<nextLeastSDN(numbers[i])<<endl; 

    return 0; 
}
