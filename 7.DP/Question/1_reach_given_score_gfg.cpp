// https://practice.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1
// like unbounded knapsack
#include <bits/stdc++.h>
using namespace std;
int solve(int n){
   vector<vector<long long int>> dp(4,vector<long long int>(n+1));
   vector<int> a={3,5,10};
   for(int i=0;i<=3;i++)
    dp[i][0]=1;
   for(long long int i=0;i<=n;i++)
    dp[0][i]=0;
   for(int i=1;i<4;i++)
   {
       for(int j=1;j<=n;j++)
       {
           if(a[i-1]<=j)
           {
               long long int take=dp[i][j-a[i-1]];
               long long int notake=dp[i-1][j];
               dp[i][j]=take+notake;
           }
           else
            dp[i][j]=dp[i-1][j];
       }
   }
   return dp[3][n];

    // vector<int> dp(n+1);
    // dp[0] = 1;
    // for(int i=1; i<=n; i++){
    //     if(i >= 3){
    //     dp[i] = dp[i-3] + dp[i];
    //     }
    //     if(i >= 5){
    //        dp[i] = dp[i-5] + dp[i];
    //     }
    //     if(i >= 10){
    //         dp[i] = dp[i-10] + dp[i];
    //     }
    // }
    // for(int i=0; i<=n; i++){
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;
    // return dp[n];


    // if(n == 0){
    //     return 1;
    // }
    // if(n >= 3){
    //     return solve(n-3) || solve(n);
    // }
    // if(n >= 5){
    //     return solve(n-5)||solve(n);
    // }
    // if(n >= 10){
    //     return solve(n-10)||solve(n);
    // }

    // return -1;
}
int main(){
    int n;
    cin>>n;
    cout<<solve(n);
    return 0;
}