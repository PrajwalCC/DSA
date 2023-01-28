#include <bits/stdc++.h>
using namespace std;
int solve(int n, int m, vector<vector<int>>& mat, int & maxi){
    vector<vector<int>>dp(n+1, vector<int>(m+1,0));
    for(int i=n-1; i>=0; i--){
        for(int j=m-1; j>=0; j--){
            int right = dp[i][j+1];
            int diagonal = dp[i+1][j+1];
            int bottom = dp[i+1][j];
            if(mat[i][j] == 1){
                dp[i][j] = 1 + min(right,min(diagonal,bottom));
                maxi = max(maxi,dp[i][j]);
            }
            else{
                dp[i][j]= 0;
            }
        }
    }
    return 1; //final ans is maxi
}
int main(){
    int n,m;
    n=2,m=2;
    vector<vector<int>> mat(n, vector<int>(m));
    mat={{1, 1},{1, 1}};
    int maxi = 0;
    solve(n,m,mat,maxi);
    cout<< maxi;
    return 0;
}