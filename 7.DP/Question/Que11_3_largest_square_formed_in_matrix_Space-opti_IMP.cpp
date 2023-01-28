#include <bits/stdc++.h>
using namespace std;
int solve(int n, int m, vector<vector<int>>& mat, int & maxi){
    // replace 2D vector with two 1D vector
    vector<int>next(m+1,0);//    dp[i+1][j+1] --> next[j+1]  , dp[i+1][j] --> next[j]
    vector<int>curr(m+1,0);//    dp[i][j] --> curr[j]        , dp[i][j+1] --> curr[j+1]
    for(int i=n-1; i>=0; i--){
        for(int j=m-1; j>=0; j--){
            int right = curr[j+1];
            int diagonal = next[j+1];
            int bottom = next[j];
            if(mat[i][j] == 1){
                curr[j] = 1 + min(right,min(diagonal,bottom));
                maxi = max(maxi,curr[j]);
            }
            else{
                curr[j]= 0;
            }
        }
        next = curr;
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