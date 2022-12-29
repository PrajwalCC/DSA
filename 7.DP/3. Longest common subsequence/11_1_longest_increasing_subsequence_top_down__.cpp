// striver 41th video of dp series ... it that again .
#include <bits/stdc++.h>
using namespace std;
int solve(int a[],int n, int idx, int prev, vector<vector<int>> dp){
    if(idx == n){
        return 0;
    }
    if( dp[idx][prev+1] != -1){
        return  dp[idx][prev+1] ;
    }
    if(prev == -1 || a[prev] < a[idx]){
        dp[idx][prev+1] = max(solve(a,n,idx+1,prev, dp), 1+solve(a,n,idx+1, idx, dp));
    }
    else{
        dp[idx][prev+1] = solve(a,n,idx+1,prev, dp);
    }
    return dp[idx][prev+1];
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
       cin>>a[i];
    }
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    cout<<solve(a,n,0,-1, dp);
    return 0;
}