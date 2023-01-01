// https://practice.geeksforgeeks.org/problems/cutted-segments1642/1
// love babbar -- https://www.youtube.com/watch?v=MFAAZW2znv8&list=PLDzeHZWIZsTomOPnCiU3J95WufjE36wsb&index=6&t=673s
#include <bits/stdc++.h>
using namespace std;
int solve(int n, int x, int y, int z){
    vector<int>dp(n+1, INT_MIN);
    
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        if(i >= x){
            dp[i] = max(dp[i-x]+1, dp[i]);
        }
        if(i >= y){
            dp[i] = max(dp[i-y]+1, dp[i]);
        }
        if(i >= z){
            dp[i] = max(dp[i-z]+1, dp[i]);
        }
    }    
    return dp[n] ;
}

int main(){
    int n;
    cin>>n;
    int x,y,z;
    cin>>x>>y>>z;
    cout<<solve(n,x,y,z);
    return 0;
}