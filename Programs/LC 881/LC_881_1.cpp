#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int numRescueBoats(vector<int> people, int limit){
    sort(people.begin(), people.end()); 

    int n = people.size(); 
    int low = 0; 
    int high = n - 1; 

    int boats = 0; 

    while(low <= high){
        if(low == high){
            // if both low and high pointers are same 
            // In the next iterations we will end the operation
            // there is not need to sum the weights pointed by low and high as they are same person
            // Just simply assign a single boat and move the pointers
                 
            ++low; 
            --high; 
        }
        else if(people[high] == limit){
            // if high is equal to limit
            // We cannot pair it with a small element 
            // So it will take a single boat
            // Now reduce the high pointer
            --high; 
        }else if(people[low] + people[high] <= limit){
            // If the sum of weights is less than limit
            // We will pair the people into same boat 
            // This will cost one boat
            // As the pair is complete
            // We will move the low pointer to next 
            // and High pointer to previous element
            ++low; 
            --high; 
        }else{
            // this block will execute if
            // people[low] + people[high] > limit
            // In this case we cannot move the low to next and check
            // As this will increase the sum greator than limit
            // Only possibility is to assign a boat to high 
            // Reduce the high by one
            
            --high; 
        }
        boats += 1;

    }

    return boats; 
}

int main(){
    // change the number of test cases
    int nInputs = 5;

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
        int n; fin>>n; 

        vector<int> people(n); 

        for(int i = 0; i < n; i++)
            fin>>people[i]; 

        int limit; fin>>limit; 

        cout<<numRescueBoats(people, limit)<<endl; 
        
        // ===== END =====
    }
    
    return 0; 
}