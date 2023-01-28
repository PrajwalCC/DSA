// https://leetcode.com/problems/reducing-dishes/
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> s){
    int n = s.size();
    vector<vector<int>>dp(n+1, vector<int>(n+1));
    for(int i=0; i<=n; i++){
        for(int t=0; t<=n; t++){
            if(i==n){
               dp[i][t]=0;
            }
        }
    }
    for(int i=n-1; i>=0; i--){
        for(int t=n-1; t>=0; t--){
            int included = s[i]*(t+1) + dp[i+1][t+1];
            int excluded = dp[i+1][t];
            dp[i][t]=max(included, excluded);
        }
    }
    return dp[0][0];
}
int main(){
    int n;
    cin>>n;
    vector<int>s(n);
    for(int i=0; i<n; i++){
        cin>>s[i];
    }
    cout<<solve(s);
    return 0;
}
