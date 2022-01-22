#include<iostream>
#include<vector>
#include<cmath>

using namespace std; 

bool isPerfectSquare(int number){
    if (number > 1) {
        long long sr = sqrt(number);
        return (sr * sr == number);
    }
    return false;
}

void simulateGame(bool &canAliceWin, int n, bool isAliceTurn = false){
    cout<<n<<boolalpha<<isAliceTurn<<endl; 
    if(n == 0){
        if(isAliceTurn) canAliceWin = true; 
        return; 
    }
    if(isPerfectSquare(n))
        simulateGame(canAliceWin, 0, !isAliceTurn); 

    if(canAliceWin) return; 

    for(int i = 1; (i *i) <= n; ++i)
        simulateGame(canAliceWin, (n - (i * i)), !isAliceTurn); 

}
bool winnerSquareGame(int n){
    bool canAliceWin = false; 
    simulateGame(canAliceWin, n); 
    return canAliceWin; 
}

int main(){
    int n; cin>>n; 
    cout<<boolalpha<<winnerSquareGame(n)<<endl; 

    return 0; 
}