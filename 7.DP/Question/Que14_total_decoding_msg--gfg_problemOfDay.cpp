#include <bits/stdc++.h>
using namespace std;
int solveTab(string s, int n, int i){
    vector<int>dp(n+1);
    dp[n]=1;
    for(int i=n-1; i>=0; i--){
        if(s[i] == '0'){
            dp[i]=0;
        }
        else{
            int single = dp[i+1];
            int two = 0;
            if(i < n-1){
                string l ="";
                l.push_back(s[i]);
                l.push_back(s[i+1]);
                if(l <= "26"){
                    two = dp[i+2];
                }
            }
            dp[i]=single+two;
        }
    }
    return dp[0];
}
int solveRecurrsion(string s, int n, int i){
    if(i == n){
        return 1;
    }
    if(s[i] == '0'){
        return 0;
    }
    else{
        int single = solveRecurrsion(s,n,i+1);
        int two = 0;
        if(i < n-1){
            string l ="";
            l.push_back(s[i]);
            l.push_back(s[i+1]);
            if(l <= "26"){
            two = solveRecurrsion(s,n,i+2);
            }
        }
        return single+two;
    }
}
int main(){
    string s;
    cin>>s;
    // cout<<solveTab(s,s.size(),0);
    cout<<solveRecurrsion(s,s.size(),0);
    return 0;
}