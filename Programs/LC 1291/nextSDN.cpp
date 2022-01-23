// Implementing the next SDN function
// SDN ==> Sequential Digit Number

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
    // Function to get next SDN Number iff SDN number is provided
    int len = numberLength(sdnNumber); 

    int nextSDN = 0; 
    
    // If last digit is 9
    // Next SDN will start from 1 but for length of (len + 1)
    if(sdnNumber % 10 == 9){
        if(len == 9) return sdnNumber; 
        for(int i = 0; i <= len; i++)
            nextSDN = (nextSDN * 10) + ((nextSDN % 10) + 1); 
    }else{
        // Given SDN Doesn't end with 9
        // Then next SDN will be the sum of
        // Given sdnNumber and 1111..len(sdnNumber)
        int ones = 0; 
        int bin = (1 << len) - 1; 
        while(bin){
            ones = (ones * 10) + 1;
            bin /= 2; 
        }
        nextSDN = sdnNumber + ones;
    }

    return nextSDN; 
}

int main(){
    vector<int> numbers{23456789, 123, 1234, 234, 
                        2345, 23456, 12, 23, 34, 89, 9, 
                        123456, 345, 56, 78, 789, 12345678,
                        123456789};

    for(int i = 0; i < numbers.size(); ++i)
        cout<<"Number: "<<numbers[i]<<" Next SDN: "<<nextSDN(numbers[i])<<endl; 

    return 0;   
}