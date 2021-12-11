// LC 784. Letter Case Permutation

#include<iostream>
#include<vector>

using namespace std; 

vector<string> letterCasePermutation(string inputString){
	vector<string> result; 
	vector<int> indices; 
	
	for(int i = 0 ; i < inputString.length(); ++i){
		if(isalpha(inputString[i]))
			indices.push_back(i);
	}	
	
	int n = indices.size(); 
	
	for(int i = 0; i < (1 << n); ++i){
		string temp = inputString; 
		int j = i; 
		int index = n - 1; 
		while(j){
			if(j & 1)
				temp[indices[index]] ^= 32;
			j >>= 1; 
			--index; 
		}
		result.push_back(temp); 
	}
	
	return result; 
}

int main(){
	string inputStr; 
	cin>>inputStr; 
	
	vector<string> result = letterCasePermutation(inputStr); 
	
	for(string permutation:result)
		cout<<permutation<<endl; 
		
	
	return 0; 
}
