#include <bits/stdc++.h>
using namespace std;
int solve( int n, int cost[]){
    vector<int> dp(n+1);
    dp[0]=cost[0];
    dp[1]=cost[1];
    
    for(int i=2; i<n; i++){
        dp[i]=min(dp[i-1],dp[i-2])+cost[i];
    }
    
    return min(dp[n-1],dp[n-2]);
}
int main(){
    // int n=3;
    // int cost[n]={10,15,20};
    int n;
    cin>>n;
    int cost[n];
    for(int i=0; i<n; i++){
       cin>>cost[i];
    }

    // cout<<min(solve(dp,n-1,cost),solve(dp,n-2,cost));
    cout<<solve(n,cost);
    return 0;
}