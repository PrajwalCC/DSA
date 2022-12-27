#include <bits/stdc++.h>
using namespace std;
int solve(int n){
    vector<int> dp(n+1);
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=n ; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}
int main(){
    int n;
    cin>>n;
    cout<<solve(n);
    return 0;
}