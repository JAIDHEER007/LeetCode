// Runtime: 0ms
// Faster Than: 100.0%
// Memory Usage: 6.2 MB
// Less Than: 73.32%

#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int compareVersion(string version1, string version2){
    int i = 0; 
    int j = 0; 

    int lenV1 = version1.length(); 
    int lenV2 = version2.length(); 

    int releaseV1 = 0;
    int releaseV2 = 0; 

    while((i < lenV1) && (j < lenV2)){
        // Parsing the release of Version 1
        while((i < lenV1) && (version1[i] != '.')){
            releaseV1 = (releaseV1 * 10) + (version1[i] - '0'); 
            i++; 
        }

        // Parsing the release of Version 2
        while((j < lenV2) && (version2[j] != '.')){
            releaseV2 = (releaseV2 * 10) + (version2[j] - '0'); 
            j++; 
        }
        

        if(releaseV1 > releaseV2) return 1; 
        else if(releaseV1 < releaseV2) return -1; 

        releaseV1 = 0; 
        releaseV2 = 0; 
        i++; 
        j++; 
    } 
    
    while(i < lenV1){
        if(version1[i] == '.'){
            if(releaseV1 > 0) return 1; 
            releaseV1 = 0; 
        }else
            releaseV1 = (releaseV1 * 10) + (version1[i] - '0'); 
        ++i; 
    }
    if(releaseV1 > 0) return 1; 

    while(j < lenV2){
        if(version2[j] == '.'){
            if(releaseV2 > 0) return -1; 
            releaseV2 = 0; 
        }else
            releaseV2 = (releaseV2 * 10) + (version2[j] - '0'); 
        ++j; 
    }
    if(releaseV2 > 0) return -1; 

    return 0; 
}

int main(){
    // change the number of test cases
    int nInputs = 7;

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