// LC 46
// Runtime: 4ms
// FT: 70.80%
// Memory Usage: 8.6mb
// LT: 14.26%

#include<iostream>
#include<vector>
using namespace std; 

void findPermutations(vector<vector<int>> &result,
					  vector<int> &nums,
					  vector<int> permutation,
					  vector<bool> visited){
					  	
	if(permutation.size() == nums.size()){
		result.push_back(permutation);
		return;
	}
	
	for(int i = 0; i < nums.size(); ++i){
		if(!visited[i]){
			permutation.push_back(nums[i]);
			visited[i] = true;
			
			findPermutations(result, nums, permutation, visited);
			
			permutation.pop_back();
			visited[i] = false;
		}
	}
}

vector<vector<int>> permute(vector<int> &nums){
	vector<vector<int>> result;
	vector<bool> visited(nums.size(), false);
	findPermutations(result, nums, {}, visited);
	
	return result; 
}

int main(){
	int n; 
	cin>>n; 
	
	vector<int> nums(n);
	for(int i = 0; i < n; ++i)
		cin>>nums[i]; 
		
	vector<vector<int>> result = permute(nums); 
	
	for(vector<int> row:result){
		for(int element:row)
			cout<<element<<" ";
		cout<<endl; 
	}
	
	return 0; 
}
