#include <bits/stdc++.h>
using namespace std;
int solve(int n,int m,int i,int j, vector<vector<int>>& mat, int & maxi, vector<vector<int>>& dp){
        if(i>=n || j>=m){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int right = solve(n,m,i,j+1,mat,maxi,dp);
        int diagonal = solve(n,m,i+1,j+1,mat,maxi,dp);
        int bottom = solve(n,m,i+1,j,mat,maxi,dp);
        if(mat[i][j] == 1){
            int ans = 1 + min(right,min(diagonal,bottom));
            maxi = max(maxi,ans);
            return dp[i][j] = ans;
        }
        else{
            return dp[i][j]= 0;
        }
    }
int main(){
    int n,m;
    n=2,m=2;
    vector<vector<int>> mat(n, vector<int>(m));
    mat={{1, 1},{1, 1}};
    int maxi = 0;
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    solve(n,m,0,0,mat,maxi,dp);
    cout<<maxi;
    return 0;
}