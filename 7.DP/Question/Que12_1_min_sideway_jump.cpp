#include <bits/stdc++.h>
using namespace std;
int solve(vector<int>& obstacle,int  n, int currLane, int currPosition,vector<vector<int>>& dp){
    if(currPosition == n){
        return 0;
    }
    if(dp[currLane][currPosition] != -1){
        return dp[currLane][currPosition]; 
    }
    if(obstacle[currPosition+1] == currLane){
        int ans = INT_MAX;
        for(int i=1; i<=3; i++){
            if(currLane != i && obstacle[currPosition] != i){
                ans = min(ans, 1+solve(obstacle,n,i,currPosition,dp));
            }
        }
        dp[currLane][currPosition] = ans;
        return  dp[currLane][currPosition];
    }
    else{
        return dp[currLane][currPosition] = solve(obstacle,n,currLane,currPosition+1,dp);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> obstacle(n);
    for(int i=0; i<n; i++){
        cin>>obstacle[i];
    }
    n=n-1; //mention in question
    vector<vector<int>>dp(4,vector<int>(n+1, -1));
    cout<< solve(obstacle,n,2,0,dp);
    return 0;
}