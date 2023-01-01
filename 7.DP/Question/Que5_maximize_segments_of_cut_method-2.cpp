// https://practice.geeksforgeeks.org/problems/cutted-segments1642/1
#include <bits/stdc++.h>
using namespace std;
int solve(int sum , vector<int> v){
    int n = v.size();
    vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(j == 0 || i == 0){
                dp[i][j] = 0;
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(v[i-1] <= j){
                if(j == v[i-1] || dp[i][j - v[i-1]] > 0){
                    
                    dp[i][j] = max(dp[i][j-v[i-1]]+1, dp[i-1][j]);
                    
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
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
    int x,y,z;
    cin>>x>>y>>z;
    vector<int> v;
    v.push_back(x);
    v.push_back(y);
    v.push_back(z);
    sort(v.begin(), v.end());
    cout<<solve(n,v);
    return 0;
}