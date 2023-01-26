#include <bits/stdc++.h>
using namespace std;
int solve(int day[], int cost[], int i, int n,vector<int>&dp){
    if(i >= n){
        return 0;
    }
    if(dp[i] != -1){
        return dp[i];
    }
    // for 1 day
    int a = solve(day,cost,i+1,n,dp) + cost[0];
    
    // for 7days
    int temp = day[i];
    int index;
    for(int j=i; j<n; j++){
        if(day[j] > temp+6){
            index = j;
           break;
        }
        index = j+1;
    }
    int b = solve(day,cost,index,n,dp)+cost[1];

    // for 30days
    temp = day[i];
    for(int j=i; j<n; j++){
        if(day[j] > temp+29){
            index = j;
           break;
        }
        index = j+1;
    }
    int c = solve(day,cost,index,n,dp)+cost[2];
    
    return dp[i]= min(a,min(b,c));
}
int main(){
    int n;
    cin>>n;
    int day[n];
    for(int i=0; i<n; i++){
        cin>>day[i];
    }
    int cost[3];
    for(int i=0; i<3; i++){
        cin>>cost[i];
    }
    vector<int>dp(n+1, -1);
    cout<<solve(day,cost,0,n, dp);
    return 0;
}