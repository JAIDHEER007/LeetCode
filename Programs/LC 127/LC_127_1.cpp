// TLE
// 33 / 50 Cases Passed

#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

bool isAdjacent(string word1, string word2){
    int len1 = word1.length(); 
    int len2 = word2.length(); 

    if(len1 != len2) return false; 
    int count = 0; 

    for(int i = 0; i < len1; i++){
        if(word1[i] != word2[i]) ++count; 
        if(count > 1) return false; 
    }

    return true; 
}

int ladderLength(string beginWord, string endWord, vector<string> wordList){
    // Visited unorderedmap
    unordered_map<string, bool> visited; 

    queue<pair<string, int>> q; 

    pair<string, int> start{beginWord, 1}; 
    q.push(start); 

    visited[start.first] = true; 

    while(!q.empty()){
        pair<string, int> curr = q.front(); 
        q.pop(); 
        visited[curr.first] = true; 

        for(int i = 0; i < wordList.size(); i++){
            string word = wordList[i]; 
            if(!visited[word] && isAdjacent(curr.first, word)){
                if(word == endWord) return (curr.second + 1); 
                q.push({word, (curr.second + 1)}); 
            }
        }
    }
     
    return 0; 
}

int main(){
    // change the number of test cases
    int nInputs = 4;

    // test case files should be input1.txt, input2.txt, ..., inputN.txt format
    for(int i = 1; i <= nInputs; i++){
        string filename = "input" + to_string(i) + ".txt"; 

        ifstream fin(filename); 
        if(!fin.is_open()){
            cout<<"Cannot Open the test case"<<endl;
            return 0; 
        }

        cout<<"======== TestCase "<<i<<" ========"<<endl;


        // Write input and output here
        // Instead of cin use fin

        // ===== START =====
        string beginWord; fin>>beginWord; 
        string endWord; fin>>endWord; 

        int wordListLen; fin>>wordListLen; 
        vector<string> wordList(wordListLen); 
        for(int i = 0; i < wordListLen; i++)
            fin>>wordList[i]; 

        cout<<ladderLength(beginWord, endWord, wordList)<<endl;  
        
        // ===== END =====
    }
    
    return 0; 
}