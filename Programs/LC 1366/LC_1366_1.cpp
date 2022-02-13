// Used Bubble Sort as the sorting technique
// Runtime: 16ms
// Faster Than: 80.46%

// Memory Usage: 11.6 MB
// Less Than: 20.92%

#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
    private:
        vector<vector<int>> data;
        vector<int> indices;  
        int n; 

        bool compare(char a, char b){
            for(int i = 0; i < n; i++){
                if((data[indices[a - 'A']][i]) != (data[indices[b - 'A']][i]))
                    return (data[indices[a - 'A']][i]) < (data[indices[b - 'A']][i]);
            }
            return a > b; 
        }

        string bubbleSort(string teams){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n - i - 1; j++){
                    if(compare(teams[j], teams[j + 1]))
                        swap(teams[j], teams[j + 1]); 
                }
            }
            return teams; 
        }
    public:
        string rankTeams(vector<string> votes){
            string teams = votes[0]; 
            // sort(teams.begin(), teams.end()); 
            
            n = teams.length(); 

            indices = vector<int>(26); 
            for(int i = 0; i < n; i++)
                indices[teams[i] - 'A'] = i; 
            
            // for(int i = 0; i < 26; i++)
            //     cout<<indices[i]<<" ";

            data = vector<vector<int>>(n, vector<int>(n, 0)); 
            for(int i = 0; i < votes.size(); i++){
                for(int j = 0; j < votes[i].length(); j++)
                    ++data[indices[votes[i][j] - 'A']][j];
            }     

            // for(int i = 0; i < n; i++){
            //     for(int j = 0; j < n; j++)
            //         cout<<data[i][j]<<" "; 
            //     cout<<endl;
            // }

           return bubbleSort(teams); 
        }
};

int main(){
    // change the number of test cases
    int nInputs = 4;

    Solution sol; 

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
        
        int nVotes; fin>>nVotes; 
        vector<string> votes(nVotes); 

        for(int i = 0; i < nVotes; i++)
            fin>>votes[i]; 
        
        cout<<sol.rankTeams(votes)<<endl; 
        
        // ===== END =====
    }
    
    return 0; 
}


// Make a 2D Array say data
// data stores the number willing votes of given team in given position
// the data array will be N X N where N is the number of teams participated

// Now implement a sorting technique 
// It should be a comparison sort
// We need to compare 2 teams and their number of votes for the position

// If two teams T1 and T2 have differet number of votes
// Then return the team with more number of votes

// If they have same number of votes then check the next position votes with the condition as above

// If the tow teams have same votes until the last position 
// Then return the team wich occurs first in the alphabetical order