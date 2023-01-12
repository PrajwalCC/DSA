// https://leetcode.com/problems/combination-sum-iv/description/
#include <bits/stdc++.h>
using namespace std;
int solve(int a[], int n, int sum, vector<int>& dp){
    if(sum == 0){
        return 1;
    }
    if(sum < 0){
        return 0;
    }
    if(dp[sum] != -1){
        return dp[sum];
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        ans += solve(a,n,sum-a[i], dp);
    }
    dp[sum] = ans;
    return dp[sum];
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int sum ;
    cin>>sum;
    vector<int>dp(sum+1, -1);
    cout<<solve(a,n,sum,dp);
    return 0;
}