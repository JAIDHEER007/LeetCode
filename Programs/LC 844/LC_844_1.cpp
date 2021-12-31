#include<iostream>
using namespace std; 

bool backspaceCompare(string s, string t) {
    string new_s = "";
    string new_t = "";

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '#')
        {
            if (new_s.length() > 0)
                new_s.pop_back();
        }
        else
            new_s += s[i];
    }

    for (int i = 0; i < t.length(); ++i)
    {
        if (t[i] == '#')
        {
            if (new_t.length() > 0)
                new_t.pop_back();
        }
        else
            new_t += t[i];
    }

    return (new_s == new_t);
}

int main(){
    string s; cin>>s; 
    string t; cin>>t; 

    cout<<boolalpha<<backspaceCompare(s, t)<<endl;

    return 0; 
}