#include<iostream>
using namespace std; 

int myAtoi(string numStr){
    int numInt = 0; 

    int i = 0; 
    int len = numStr.length(); 

    bool isPositive = true; 
    bool isSignIdentified = false;
    bool ignoreLWP = true;  
    while(i < len){
        // If whitespace 
        if(numStr[i] == ' '){
            // is leading wp
            if(!ignoreLWP) break;  
        }else{
            // It is not a whitespace
            ignoreLWP = false; 
            // If it is number
            // Check for fucking overflow
            if(numStr[i] >= '0' && numStr[i] <= '9'){
                if((numInt > (INT_MAX / 10)) || 
                  ((INT_MAX - (numInt * 10)) < (numStr[i] - '0'))){
                    if(isPositive) return INT_MAX; 
                    else return INT_MIN; 
                }
                numInt = (numInt * 10) + (numStr[i] - '0'); 
            }else{
                // Not a number
                // Maybe a sign
                if(numStr[i] == '-' || numStr[i] == '+'){
                    if(!isSignIdentified)
                        isSignIdentified = true; 
                    else break; 
                    isPositive = (numStr[i] == '+');
                }else break; // it is a character so break it
            }
            
        }
        ++i;
    }
    return (numInt * ((isPositive)?(1):(-1))); 
}

int main(){
    string numStr; 
    getline(cin, numStr); 
    // cout<<numStr<<endl;
    cout<<myAtoi(numStr)<<endl;

    return 0; 
}