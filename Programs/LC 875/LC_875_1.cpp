// Time Limit Error
// O((n * max(piles)) + n)

#include<iostream>
#include<vector>
#include<cmath>
using namespace std; 

int minEatingSpeed(vector<int> piles, int h){
    int kmax = INT_MIN; 

    for(int i = 0; i < piles.size(); ++i)
        kmax = max(kmax, piles[i]); 

    for(int k = 1; k <= kmax; ++k){
        int hcount = 0; 
        int i = 0;  
        for(;i < piles.size(); ++i){
            hcount += ceil(float(piles[i]) / float(k)); 
            if(hcount > h) break; 
        }
        if((hcount == h) && (i == piles.size())) return k; 
    }

    return -1; 
}

int main(){
    int n; cin>>n; 
    vector<int> piles(n); 
    for(int i = 0; i < n; ++i)
        cin>>piles[i]; 

    int h; cin>>h; 

    cout<<minEatingSpeed(piles, h)<<endl; 

    return 0; 
}