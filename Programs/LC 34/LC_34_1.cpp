// LC 34
// Find First and Last Position of Element in Sorted Array

// RT: 0ms
// FT: 100%

// MU: 13.9 MB
// LT: 6.37%

#include<iostream>
#include<vector>

using namespace std; 

int binarySearch(vector<int> nums, int key){
	int start = 0; 
	int end = nums.size() - 1; 
	
	while(start <= end){
		int mid = end + (start - end) / 2; 
		
		if(nums[mid] == key) return mid; 
		if(nums[mid] < key) start = mid + 1; 
		else end = mid - 1; 
	}
	
	return -1; 
}

vector<int> serachRange(vector<int> &nums, int target){
	int index = binarySearch(nums, target); 
	
	if(index == -1) return {-1, -1};
	
	// Finding the left Index
	int left = index; 
	while((left >= 0) && (nums[left] == target)) --left;
	
	// Finding the right index
	int right = index;
	int numsSize = nums.size(); 
	while((right < numsSize) && (nums[right] == target)) ++right;
	
	return {(left + 1), (right - 1)}; 
}

int main(){
	int n; cin>>n;
	vector<int> nums(n); 
	
	for(int i = 0; i < n; ++i)
		cin >> nums[i];
		
	int target; 
	cin>>target; 
		
	vector<int> range = serachRange(nums, target); 
	cout<<range[0]<<" "<<range[1]<<endl; 
	
	return 0; 
}
