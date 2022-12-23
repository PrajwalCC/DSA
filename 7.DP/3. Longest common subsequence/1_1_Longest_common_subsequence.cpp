#include <bits/stdc++.h>
using namespace std;
int noLongestSub(string s1, string s2, int n, int m, vector<vector<int>>dp){ 
    if(n==0 || m==0){
        return 0;
    }
    if(dp[n][m] != -1){
        return dp[n][m];
    }
    if(s1[n-1] == s2[m-1]){
        return dp[n][m] = 1 + noLongestSub(s1,s2,n-1,m-1, dp);
    }
    else{
        return dp[n][m] = max(noLongestSub(s1,s2,n-1,m,dp), noLongestSub(s1,s2, n, m-1,dp));
    }
}
int main(){
    string s1, s2;
    cin>>s1>>s2;
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
    cout<<noLongestSub(s1,s2, n, m, dp);
    return 0;
}