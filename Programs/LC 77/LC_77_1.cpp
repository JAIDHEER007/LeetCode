// Runtime: 436ms
// FT: 15.99%
// Memory Usage: 164.4 mb
// LT: 12.18%

#include<iostream>
#include<vector>
using namespace std; 

void findCombinations(vector<vector<int>> &result,
		      int &n, int &k,
		      vector<int> arr = {},
		      int currNum = 1){

	// Base Case
	if(arr.size() == k){
		result.push_back(arr); 
		return;
	}	
	
	// Recursive Case	
	for(int i = currNum; i <= n; ++i){
		arr.push_back(i);
		findCombinations(result, n, k, arr, (i + 1));
		arr.pop_back(); 
	}			  	
}

vector<vector<int>> combinations(int n, int k){
	vector<vector<int>> result; 
	findCombinations(result, n, k);
	return result; 
}

int main(){
	int n, k;
	cin>>n>>k; 
	
	vector<vector<int>> result = combinations(n, k); 
	
	for(vector<int> row:result){
		for(int element:row)
			cout<<element<<" ";
		cout<<endl; 
	}
	
	return 0; 
}
