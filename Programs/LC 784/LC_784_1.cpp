// LC 784. Letter Case Permutation

#include<iostream>
#include<vector>

using namespace std; 

void changeCase(char &ch){
	if((ch >= 'a') && (ch <= 'z')) ch = toupper(ch);
	else ch = tolower(ch); 
}

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
				changeCase(temp[indices[index]]);
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
