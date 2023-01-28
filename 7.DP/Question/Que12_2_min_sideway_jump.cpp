#include <bits/stdc++.h>
using namespace std;
int solve(int obstacle[],int  n){
    vector<vector<int>>dp(4,vector<int>(n+1, INT_MAX));
    dp[0][n]=0;
    dp[1][n]=0;
    dp[2][n]=0;
    dp[3][n]=0;
    for(int j=n-1; j>=0; j--){
        for(int i=3; i>=0; i--){
            if(obstacle[j+1] == i){
                int ans = INT_MAX;
                for(int k=1; k<=3; k++){
                    if(i != k && obstacle[j] != k){
                        ans = min(ans, 1+dp[k][j+1]); //here is the catch, we replace j with j+1, becoz dp[k][j] may not be calculated yet
                        // so we have taken dp[k][j+1] which is already calculated
                    }
                }
                dp[i][j]=ans;
            }
            else{
                dp[i][j]= dp[i][j+1];
            }
        }
    }
    return min(dp[2][0],  min(1+dp[1][0], 1+dp[3][0]));
}
int main(){
    int n;
    cin>>n;
    int obstacle[n];
    for(int i=0; i<n; i++){
        cin>>obstacle[i];
    }
    cout<<solve(obstacle,n);
    return 0;
}