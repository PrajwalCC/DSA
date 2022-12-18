#include <bits/stdc++.h>
using namespace std;
int unboundedKnapsack(int w[], int v[], int weight, int n){
    vector<vector<int> > dp(n + 1, vector<int>(weight + 1));

    for(int i=0; i<=n;i++){
        for(int j=0; j<=weight;j++){
            if(n==0 || weight==0){
                dp[i][j]=0;
            }
        }
    }
    for(int i=1; i<=n;i++){
        for(int j=1; j<=weight;j++){
            // if(n==0 || w==0){
            //     dp[i][j]=0;
            // }
            
            if(w[i-1] <= j){
                dp[i][j] = max(v[i-1]+dp[i][j-w[i-1]] , dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
            
        }
    }
    return dp[n][weight];
}
int main(){
    int n;
    cin>>n;
    int w[n],v[n];
    for(int i=0; i<n; i++){
        cin>>w[i];
    }
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    int weight;
    cin>>weight;
    cout<<unboundedKnapsack(w,v,weight,n);
    return 0;
}