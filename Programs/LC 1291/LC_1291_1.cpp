// Runtime: 0ms
// Faster Than: 100.00%

// Memory Usage: 6.2MB
// Less Than: 76.43%

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
        if(len == 9) return INT_MAX; 
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


vector<int> sequentialDigits(int low, int high){
    vector<int> result; 
    int nextLeastSdn = nextLeastSDN(low);
    if(nextLeastSdn <= high) result.push_back(nextLeastSdn); 
    else return result; 

    while(true){
        int nextSdn = nextSDN(*(result.rbegin())); 
        if(nextSdn > high) break; 
        result.push_back(nextSdn); 
    }

    return result; 
}

int main(){
    int low; cin>>low; 
    int high; cin>>high; 

    vector<int> result = sequentialDigits(low, high); 

    for(int i = 0; i < result.size(); i++)
        cout<<result[i]<<endl; 

    return 0; 
}