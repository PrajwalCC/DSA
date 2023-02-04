// https://practice.geeksforgeeks.org/problems/dice-throw5349/1
#include <bits/stdc++.h>
using namespace std;
// Recurrsion
// int solve(int n, int m, int x, int i){
//     if(i == n){
//         if(x == 0){
//            return 1;
//         }else{
//            return 0;
//         }
//     }
//     int ans = 0;
//     for(int j=1; j<=m; j++){
//         ans= ans+solve(n,m,x-j, i+1);
//     }
//     return ans;
// }
// Tabulation
long long solve(int n, int m, int x, int i){
    vector<vector<long long>>dp(n+1, vector<long long>(x+1));
    for(int i=0; i<=n; i++){
        for(int k=0; k<=x; k++){
            if(i == n){
                if(k == 0){
                    dp[i][k]= 1;
                }
                // for k<0 not valid
            }
            if(k == 0 && i != n){
                dp[i][k]= 0;
            }
        }
    }
    for(int i=n-1; i>=0; i--){
        for(int k=1; k<=x; k++){ 
            long long ans = 0;
            for(int j=1; j<=m; j++){
                if(k >= j){ 
                    ans= ans+dp[i+1][k-j];
                }
            }
            dp[i][k] = ans;
        }
    }
    return dp[0][x];
}
int main(){
    int n,m,x;

    m=6,n=3,x=12;
    // m=6,n=6,x=6;
    // m=2,n=3,x=6;
    m=12,n=19,x=49;
    cout<<solve(n,m,x,0);
    return 0;
}