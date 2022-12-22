#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &dp, int n, int cost[]){
    if(n==0){
        return cost[0];
    }
    if(n==1){
        return cost[1];
    }
    if(dp[n]!= -1){
        return dp[n];
    }
    dp[n]=min(solve(dp,n-1,cost), solve(dp,n-2,cost))+cost[n];
    return dp[n];
}
int main(){
    int n=3;
    int cost[n]={10,15,20};
    vector<int> dp(n+1, -1);
    // cout<<min(solve(dp,n-1,cost),solve(dp,n-2,cost));
    cout<<min(solve(dp,n-1,cost),solve(dp,n-2,cost));
    return 0;
}