// https://practice.geeksforgeeks.org/problems/dice-throw5349/1
#include <bits/stdc++.h>
using namespace std;
// int solve(int n, int m, int x, int i){
//     if(i==0 && x==0){
//         return 1;
//     }
//     if(i==0 && x!=0){
//         return 0;
//     }
//     if(x ==0 && i !=0){
//         return 0;
//     }
//     int ans = 0;
//     for(int j=1; j<=m; j++){
//         ans = ans + solve(n,m,x-j,i-1);
//     }
//     return ans;
// }
long long solve(int n, int m, int x, int i){
    vector<vector<long long>>dp(n+1, vector<long long>(x+1));
    for(int i=0; i<=n; i++){
        for(int k=0; k<=x; k++){
            if(i==0 && k==0){
                dp[i][k]=1;
            }
            if(i==0 && k!=0){
                dp[i][k]= 0;
            }
            if(k ==0 && i !=0){
                dp[i][k]= 0;
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int k=1; k<=x; k++){
            long long ans = 0;
            for(int j=1; j<=m; j++){
                if(k-j >= 0){
                    ans = ans + dp[i-1][k-j];
                }
            }
            dp[i][k] = ans;
        }
    }
    return dp[n][x];
}
int main(){
    int n,m,x;

    // m=6,n=3,x=12;
    m=12,n=19,x=49;//Not working for this test case
    cout<<solve(n,m,x,n);
    return 0;
}