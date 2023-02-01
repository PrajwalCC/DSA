// https://practice.geeksforgeeks.org/problems/844b4fdcd988ac5461324d62d43f7892749a113c/1

#include <bits/stdc++.h>
using namespace std;
long long int solveTab(int r[],int g[],int b[],int n, int i, int c){
    vector<vector<long long int>>dp(n+1, vector<long long int>(4));
    dp[n][0]=0;
    dp[n][1]=0;
    dp[n][2]=0;
    dp[n][3]=0;
    for(int i=n-1; i>=0; i--){
        for(int j=3; j>=0; j--){
            if(j == 0){
                dp[i][j] = min(dp[i+1][1]+r[i], min(dp[i+1][2]+g[i],dp[i+1][3]+b[i]));
            }
            else if(j == 1){
                dp[i][j] = min(dp[i+1][2]+g[i], dp[i+1][3]+b[i]);
            }
            else if(j == 2){
                dp[i][j] = min(dp[i+1][1]+r[i], dp[i+1][3]+b[i]);
            }
            else{
                dp[i][j] = min(dp[i+1][1]+r[i], dp[i+1][2]+g[i]);
            }
        }
    }
    return dp[0][0];
}
int solveRecurrsion(int r[],int g[],int b[],int n, int i, int c){
    if(i == n){
        return 0;
    }
    if(c == 0){
        return min(solveRecurrsion(r,g,b,n,i+1,1)+r[i], min(solveRecurrsion(r,g,b,n,i+1,2)+g[i],solveRecurrsion(r,g,b,n,i+1,3)+b[i]));
    }
    else if(c==1){
        return min(solveRecurrsion(r,g,b,n,i+1,2)+g[i], solveRecurrsion(r,g,b,n,i+1,3)+b[i]);
    }
    else if(c == 2){
        return min(solveRecurrsion(r,g,b,n,i+1,1)+r[i], solveRecurrsion(r,g,b,n,i+1,3)+b[i]);
    }
    else{
        return min(solveRecurrsion(r,g,b,n,i+1,1)+r[i], solveRecurrsion(r,g,b,n,i+1,2)+g[i]);
    }
}
int main(){
    int n;
    n=3;
    // int r[] = {2, 1, 3};
    // int g[] = {3, 2, 1};
    // int b[] = {1, 3, 2};
    int r[] = {1, 1, 1};
    int g[] = {2, 2, 2};
    int b[] = {3, 3, 3};
    // cout<<solveRecurrsion(r,g,b,n,0,0);
    cout<<solveTab(r,g,b,n,0,0);
    return 0;
}