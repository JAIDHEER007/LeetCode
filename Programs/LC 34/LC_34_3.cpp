// LC 34
// Using Binary Search only

#include<iostream>
#include<vector>

using namespace std; 

int BS(vector<int> &nums, int key){
	int start = 0; 
	int end = nums.size() - 1; 
	
	while(start <= end){
		int mid = end + (start - end) / 2; 
		
		if(nums[mid] == key) return mid; 
		else if(nums[mid] < key) start = mid + 1; 
		else end = mid - 1; 
	}
	
	return -1; 
}

int BSL(vector<int> nums, int end, int key){
	int start = 0; 
	
	while(start <= end){
		int mid = end + (start - end) / 2; 
		
		if(nums[mid] == key){
			if((mid == 0) || (nums[mid - 1] != key)) return mid; 
			end = mid - 1; 
		}else if(nums[mid] < key) start = mid + 1; 
		else end = mid - 1; 
	}
	return -1; 
}

int BSR(vector<int> nums, int start, int key){
	int numsSize = nums.size(); 
	int end = numsSize - 1; 
	
	while(start <= end){
		int mid = end + (start - end) / 2; 
		
		if(nums[mid] == key){
			if((mid == numsSize - 1) || (nums[mid + 1] != key)) return mid; 
			start = mid + 1; 
		}else if(nums[mid] < key) start = mid + 1; 
		else end = mid - 1; 
	}
	return -1; 
}


vector<int> searchRange(vector<int> &nums, int target){
	int index = BS(nums, target); 
	
	if(index == -1) return {-1, -1}; 
	
	return {BSL(nums, index, target), BSR(nums, index, target)};
}

int main(){
	int n; cin>>n; 
	vector<int> nums(n); 
	
	for(int i = 0; i < n; ++i)
		cin>>nums[i];
		
	int target; cin>>target; 
	
	vector<int> result = searchRange(nums, target); 
	
	cout<<result[0]<<" "<<result[1]<<endl; 
	
	return 0; 
}
