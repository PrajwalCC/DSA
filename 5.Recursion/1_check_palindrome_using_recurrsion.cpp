#include <bits/stdc++.h>
using namespace std;

bool solve(string &s, int i){
    if(i >= s.length()/2){
       return true;
    }
    if(s[i] != s[s.length()-1-i]){
       return false;
    }
    return solve(s,i+1);
}
int main(){
    string s;
    cin>>s;
    cout<< solve(s,0);
    return 0;
}