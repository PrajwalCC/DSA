// https://practice.geeksforgeeks.org/problems/get-minimum-squares0538/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
#include <bits/stdc++.h>
using namespace std;
int solve(int n, vector<int> &dp){
    if(n == 0){
        return 0;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int ans = n;
    for(int i= sqrt(n); i>0; i--){
        ans = min(solve(n - (i*i), dp)+1, ans);
    }
    dp[n] = ans;
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1, -1);
    cout<<solve(n, dp);
    return 0;
}