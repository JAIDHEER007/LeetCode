#include<iostream>
#include<vector>

using namespace std; 

void merge(vector<int> &arr1, int m, vector<int> &arr2, int n){
    int i = m - 1; 
    int j = n - 1; 

    int k = (m + n) - 1; 

    while((i >= 0) && (j >= 0)){
        if(arr1[i] > arr2[j]){
            arr1[k] = arr1[i]; 
            --i; 
        }else{
            arr1[k] = arr2[j]; 
            --j; 
        }
        --k;
    }

    while(i >= 0)
        arr1[k--] = arr1[i--]; 
    
    while(j >= 0)
        arr1[k--] = arr2[j--]; 
}

int main(){
    int n1; cin>>n1;    
    vector<int> arr1(n1); 
    for(int i = 0; i < n1; i++)
        cin>>arr1[i]; 

    int n2; cin>>n2;    
    vector<int> arr2(n2); 
    for(int i = 0; i < n2; i++)
        cin>>arr2[i];

    vector<int> zeroes(n1, 0); 
    arr1.insert(arr1.end(), zeroes.begin(), zeroes.end());

    merge(arr1, n1, arr2, n2); 

    for(int i = 0; i < arr1.size(); i++)
        cout<<arr1[i]<<" "; 

    return 0;  
}