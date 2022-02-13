// Used Quick Sort as the sorting technique
// Runtime: 20ms

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

        int partition (string &teams, int low, int high){
            int pivot = teams[high]; 
            int i = (low - 1);         
            for(int j = low; j <= high - 1; j++){
                if(compare(pivot, teams[j])){
                    i++; 
                    swap(teams[i], teams[j]);
                }
            }
            swap(teams[i + 1], teams[high]);
            return (i + 1);
        }

        void quickSort(string &teams, int start, int end){
            if (start < end){
                int p = partition(teams, start, end);
        
                quickSort(teams, start, p - 1);
                quickSort(teams, p + 1, end);
            }
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

            quickSort(teams, 0, (n - 1)); 
            return teams; 
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