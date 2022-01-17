// Runtime: 0ms 
// Faster Than: 100.00%
// Memery Usage: 6.5 MB
// Less than: 50.50%

#include<iostream>
#include<unordered_map>
#include<vector>
#include<sstream>

using namespace std; 

bool wordPattern(string pattern, string s){
    unordered_map<string, char> tokenTable; 
    vector<bool> patternTable(26, false); 

    int i = 0; 
    int pn = pattern.length(); 

    stringstream ss(s); 
    string token; 

    while(ss >> token){
        if(i == pn) return false; 
        if(tokenTable[token]){  // These brackets absolutely necessary
            if(tokenTable[token] != pattern[i]) return false; 
        }
        else{
            if(patternTable[pattern[i] - 'a']) return false;
            patternTable[pattern[i] - 'a'] = true;  
            tokenTable[token] = pattern[i]; 
        }
        ++i; 
    }
    
    return (i == pn); 
}

int main(){
    string pattern; 
    cin>>pattern; 

    cin.clear(); 
    fflush(stdin); 

    string s; 
    getline(cin, s); 

    cout<<boolalpha<<wordPattern(pattern, s)<<endl; 

    return 0; 
}