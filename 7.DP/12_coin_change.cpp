// subset sum + unbounded
#include <bits/stdc++.h>
using namespace std;
int allPossibleWaysOfSum(int coin[], int n, int sum){
    vector<vector<int>>dp(n+1, vector<int>(sum+1));
    for(int i=0; i<=n; i++){
       for(int j=0; j<=sum; j++){
           if(i==0){
            dp[i][j]=0;
           }
           if(j==0){
            dp[i][j]=1;
           }
       }
    }
    for(int i=1; i<=n; i++){
       for(int j=0; j<=sum; j++){
           if(coin[i-1] <= j){
            dp[i][j] = dp[i][j-coin[i-1]] + dp[i-1][j];
           }
           else{
            dp[i][j] = dp[i-1][j];
           }
       }
    }
    return dp[n][sum];
}
int main(){
    int n;
    cin>>n;
    int coin[n];
    for(int i=0; i<n; i++){
       cin>>coin[i];
    }
    int sum;
    cin>>sum;
    cout<< allPossibleWaysOfSum(coin, n, sum);
    return 0;
}