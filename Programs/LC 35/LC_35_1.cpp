// LC 35
// Search INsert Position

#include<iostream>
#include<vector>
using namespace std; 

int searchInsert(vector<int>& nums, int target) {
    int start = 0; 
    int end = nums.size() - 1; 
        
    while(start <= end){
        int mid = end + (start - end) / 2; 
            
        if(nums[mid] == target) return mid; 
        else if(nums[mid] < target) start = mid + 1; 
        else end = mid - 1; 
    }
        
    return end + 1; 
}

int main(){
	int n; 
	cin>>n;
	
	vector<int> nums(n); 
	for(int i = 0; i < n; ++i)
		cin>>nums[i]; 
		
	int target; 
	cin>>target; 
	
	cout<<searchInsert(nums, target)<<endl;
	
	return 0; 
}
