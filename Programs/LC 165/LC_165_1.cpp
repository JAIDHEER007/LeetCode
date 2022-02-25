// Runtime: 3ms
// Faster Than: 31.35%
// Memory Usage: 6.2 MB
// Less Than: 35.61%

#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int compareVersion(string version1, string version2){
    int i = 0; 
    int j = 0; 

    int lenV1 = version1.length(); 
    int lenV2 = version2.length(); 

    int release = 0; 
    vector<int> releases1, releases2; 

    while(i < lenV1){
        if(version1[i] == '.'){
            releases1.push_back(release);             
            release = 0; 
        }else{
            release = (release * 10) + (version1[i] - '0'); 
        }
        i++; 
    }
    releases1.push_back(release); 
    release = 0;


    while(j < lenV2){
        if(version2[j] == '.'){
            releases2.push_back(release);             
            release = 0; 
        }else{
            release = (release * 10) + (version2[j] - '0'); 
        }
        j++; 
    }
    releases2.push_back(release); 

    i = 0; 
    j = 0; 
    lenV1 = size(releases1); 
    lenV2 = size(releases2); 

    while((i < lenV1) && (j < lenV2)){
        if(releases1[i] > releases2[j])
            return 1; 
        else if(releases1[i] < releases2[j])
            return -1; 
        ++i; 
        ++j; 
    }

    while(i < lenV1){
        if(releases1[i++] > 0) return 1; 
    }

    while(j < lenV2){
        if(releases2[j++] > 0) return -1; 
    } 

    return 0; 
}

int main(){
    // change the number of test cases
    int nInputs = 6;

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
        string version1; fin>>version1; 
        string version2; fin>>version2; 

        cout<<compareVersion(version1, version2)<<endl; 

        // ===== END =====
    }
    
    return 0; 
}