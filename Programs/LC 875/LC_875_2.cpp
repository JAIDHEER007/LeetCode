// O((n * log(max(piles))) + n)
// Failed for small inputs with large numbers
// Inacurate
// 116 / 119 Casses Passed
// Gotta Improve the Accuracy 

#include<iostream>
#include<vector>
#include<cmath>
using namespace std; 

int timeTaken(vector<int> piles, int k){
    int time = 0; 
    for(int i = 0 ; i < piles.size(); ++i)
        time += ceil(float(piles[i]) / float(k)); 
    return time; 
}

int minEatingSpeed(vector<int> piles, int h){
    int kmax = INT_MIN; 

    for(int i = 0; i < piles.size(); ++i)
        kmax = max(kmax, piles[i]); 

    int start = 1; 
    int end = kmax; 

    while(start <= end){
        int mid = end + (start - end) / 2; 

        int tt = timeTaken(piles, mid); 
        // cout<<tt<<" "<<mid<<endl;

        if(tt <= h)  end = mid - 1;
        else start = mid + 1; 
    }

    return start; 
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