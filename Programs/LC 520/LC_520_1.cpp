#include<iostream>
using namespace std; 

bool detectCapitalUse(string word) {
    int capCount = 0;
    int capPossn = -1;
    
    int wordLen = word.length();
    
    for(int i = 0; i < wordLen; ++i){
        if(isupper(word[i])){
            ++capCount;
            capPossn = i;
        }
    }
            
    if(capCount == 0)
            return true;
    else{
        if(capCount == 1)
            return capPossn == 0;
        return capCount == wordLen; 
    }
            
    return false;
}

int main(){
    string word; 
    cin>>word; 

    cout<<boolalpha<<detectCapitalUse(word)<<endl; 

    return 0; 
}