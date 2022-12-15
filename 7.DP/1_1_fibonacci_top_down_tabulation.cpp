#include <bits/stdc++.h>
using namespace std;
int fib(int n, vector<int>& dp){
   if(n==1 || n==0){
    return 1;
   }
   if(dp[n] != -1){
     return dp[n];
   }
   dp[n]=fib(n-1, dp)+fib(n-2, dp);
   return dp[n];
}
int main(){
    int n=7;
    vector<int> dp;
    for(int i=0; i<n+1; i++){
        dp.push_back(-1);
    }
    cout<<fib(n,dp);
    return 0;
}