// LC 78
// Subsets

#include<iostream>
#include<vector>

using namespace std; 

vector<vector<int>> subsets(vector<int> &nums){
	int n = nums.size(); 
	
	vector<vector<int>> result; 
	
	for(int i = 0; i < (1 << n); ++i){
		int j = i;
		vector<int> subset;  
		for(int k = 0; k < n; ++k){
			if(j & 1)
				subset.push_back(nums[k]);
			j >>= 1; 
		}
		result.push_back(subset); 
	}
	
	return result;
}

int main(){
	int n; cin>>n; 
	
	vector<int> arr(n); 
	for(int i = 0; i < n; ++i)
		cin>>arr[i]; 
		
	vector<vector<int>> result = subsets(arr); 
	
	for(vector<int> row:result){
		for(int element:row)
			cout<<element<<" "; 
		cout<<endl; 
	}
	
	return 0; 
}
