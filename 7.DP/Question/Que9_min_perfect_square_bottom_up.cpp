// https://practice.geeksforgeeks.org/problems/get-minimum-squares0538/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
#include <bits/stdc++.h>
using namespace std;
int solve(int n){
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    for(int i= 1; i<=n; i++){
        for(int j=1; j<=sqrt(i); j++){
            if(i - (j*j) >= 0){
                dp[i] = min(dp[i - (j*j)]+1, dp[i]);
            }
        }
        
    }
    
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    
    cout<<solve(n);
    return 0;
}