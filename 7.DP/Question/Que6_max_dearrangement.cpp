#include <bits/stdc++.h>
using namespace std;
long long solve(int n){
    vector<long long int>dp(n+1);
    dp[1] = 0;
    dp[2] = 1;
    for(int i=3; i<=n; i++){
        dp[i]=(((i-1)% 1000000007)*((dp[i-1] + dp[i-2]) % 1000000007))% 1000000007;
    }
    return dp[n]% 1000000007;
}
int main(){
    int n;
    cin>>n;
    cout<<solve(n);
    return 0;
}