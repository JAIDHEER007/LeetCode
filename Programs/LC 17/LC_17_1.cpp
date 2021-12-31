// Runtime: 0ms
// Faster Than: 100.00%

// Memory Usage: 6.5MB
// Less Than: 67.14%

#include<iostream>
#include<vector>
using namespace std;

vector<string> letters{"#", "#",
                       "abc", "def",
                       "ghi", "jkl",
                       "mno", "pqrs", 
                       "tuv", "wxyz" }; 

void findCombinations(vector<string> &combinations, string &digits, int index, string temp){
    // Base Case
    if(index == digits.length()){
        combinations.push_back(temp); 
        return;
    }

    for(int i = 0; i < letters[digits[index] - '0'].length(); ++i)
        findCombinations(combinations, digits, (index + 1), (temp + letters[digits[index] - '0'][i]));
}

vector<string> letterCombinations(string digits){
    if(digits.length() == 0) return {};

    vector<string> combinations; 
    findCombinations(combinations, digits, 0, ""); 
    return combinations; 
}

int main(){
    string digits; 
    cin>>digits; 

    vector<string> combinations = letterCombinations(digits); 

    for(int i = 0; i < combinations.size(); ++i)
        cout<<combinations[i]<<endl; 

    return 0; 
}