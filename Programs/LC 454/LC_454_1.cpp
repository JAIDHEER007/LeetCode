#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std; 

int fourSumCount(vector<int> nums1, vector<int> nums2, vector<int> nums3, vector<int> nums4){
    int n = nums1.size(); 

    unordered_map<int, int> umap; 

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            ++umap[nums1[i] + nums2[j]];
    }

    int count = 0; 

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            count += umap[-(nums3[i] + nums4[j])]; 
    }

    return count; 
}

int main(){
    int n; 
    cin>>n; 

    vector<int> nums1(n), nums2(n), nums3(n), nums4(n); 

    for(int i = 0; i < n; i++) cin>>nums1[i];
    for(int i = 0; i < n; i++) cin>>nums2[i];
    for(int i = 0; i < n; i++) cin>>nums3[i];
    for(int i = 0; i < n; i++) cin>>nums4[i];

    cout<<fourSumCount(nums1, nums2, nums3, nums4); 

    return 0; 
}