// Toggling a Case of Character using Bitwise operators

#include<iostream>
using namespace std; 

int main(){
	string text; 
	cin>>text; 
	
	for(int i = 0; i < text.length(); ++i){
		text[i] ^= 32;
	}
	
	cout<<text<<endl; 
	
	return 0; 
}
