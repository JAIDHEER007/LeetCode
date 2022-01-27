#include<iostream>
#include<vector>
#include<string>

using namespace std; 

void printBINS(vector<int> arr){
    int maxNumber = INT_MIN; 
    int n = arr.size(); 

    for(int i = 0; i < n; i++)
        maxNumber = max(maxNumber, arr[i]); 
    cout<<"Max Number: "<<maxNumber<<endl; 

    int maxBC = 0;
    while(maxNumber){
        ++maxBC; 
        maxNumber >>= 1; 
    } 
    cout<<"Max Bit Count: "<<maxBC<<endl; 

    for(int i = 0; i < n; i++){
        string bin = ""; 
        int temp = arr[i]; 

        while(temp){
            bin = to_string(temp & 1) + bin;
            temp >>= 1;  
        }
        cout<<(string(maxBC - bin.length(), '0') + bin)<<endl; 
    }
}

int main(){
    int n; 
    cin>>n; 

    vector<int> arr(n); 
    for(int i = 0; i < n; i++)
        cin>>arr[i]; 

    printBINS(arr); 

    return 0; 
}