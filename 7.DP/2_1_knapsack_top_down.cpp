#include <bits/stdc++.h>
using namespace std;

int knapsack(int wt[], int v[], int w, int n, int** dp){
    if(n==0 || w==0){
        return 0;
    }

    if(dp[n][w] != -1){
        return dp[n][w];
    }

    if(wt[n-1] <= w){
        return dp[n][w] = max(v[n-1]+knapsack(wt,v,w-wt[n-1],n-1, dp), knapsack(wt,v,w,n-1,dp));
    }

    else{
        return dp[n][w] = knapsack(wt,v,w,n-1,dp);
    }
}

int main(){
    // int n;
    // cin>>n;
    // int wt[n],v[n];
    // for(int i=0; i<n; i++){
    //     cin>>wt[i];
    // }
    // for(int i=0; i<n; i++){
    //     cin>>v[i];
    // }
    // int w;
    // cin>>w;
    int n=3,w=4;
    int wt[3]={1,3,4};
    int v[3]={3,3,5};
    
    int** dp;
    dp = new int*[n+1];
    for (int i = 0; i <= n; i++){
        dp[i] = new int[w + 1];
    }

    for(int i=0; i<=n;i++){
        for(int j=0; j<=w;j++){
            dp[i][j]=-1;
        }
    }    
    
    cout<<knapsack(wt,v,w,n,dp);
    return 0;
}