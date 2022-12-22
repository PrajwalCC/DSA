#include <bits/stdc++.h>
using namespace std;
int fib(int n, vector<int>& dp){
    dp.push_back(1);
    dp.push_back(1);
    
    for(int i=2; i<=n; i++){
        int temp=dp[i-1]+dp[i-2];
        dp.push_back(temp);
    }

    return dp[n];
}
int main(){
    int n = 4;
    vector<int> dp;
    cout<<fib(n,dp);
    return 0;
}