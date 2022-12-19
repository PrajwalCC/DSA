#include <bits/stdc++.h>
using namespace std;

int knapsack(int wt[], int v[], int w, int n){
    // Dynamic Array
    // int** dp;
    // dp = new int*[n+1];
    // for (int i = 0; i <= n; i++){
    //     dp[i] = new int[w + 1];
    // }

    // static array
    // int dp[10][10];
    // 2-D vector
    vector<vector<int> > dp(n + 1, vector<int>(w + 1));

    for(int i=0; i<=n;i++){
        for(int j=0; j<=w;j++){
            if(n==0 || w==0){
                dp[i][j]=0;
            }
        }
    }

    for(int i=1; i<=n;i++){
        for(int j=1; j<=w;j++){
            // if(n==0 || w==0){
            //     dp[i][j]=0;
            // }
            
            if(wt[i-1] <= j){
                dp[i][j] = max(v[i-1]+dp[i-1][j-wt[i-1]] , dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
            
        }
    }

    // for(int i=0; i<=n;i++){
    //     for(int j=0; j<=w;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return dp[n][w];
}

int main(){
    int n;
    cin>>n;
    int wt[n],v[n];
    int w;
    cin>>w;
    for(int i=0; i<n; i++){
        cin>>wt[i];
    }
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    // int n=3,w=4;
    // int wt[3]={1,3,4};
    // int v[3]={1,3,5};    
    cout<<knapsack(wt,v,w,n);
    return 0;
}