// https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1
// here our main focus is on maxi*, our final ans is maxi
#include <bits/stdc++.h>
using namespace std;
int solve(int n,int m,int i,int j, vector<vector<int>> mat, int & maxi){
    if(i>=n || j>=m){
        return 0;
    }
    int right = solve(n,m,i,j+1,mat,maxi);
    int diagonal = solve(n,m,i+1,j+1,mat,maxi);
    int bottom = solve(n,m,i+1,j,mat,maxi);
    if(mat[i][j] == 1){
        int ans = 1 + min(right,min(diagonal,bottom));
        maxi = max(maxi,ans);
        return ans;
    }
    else{
        return 0;
    }
}
int main(){
    int n,m;
    n=2,m=2;
    vector<vector<int>> mat(n, vector<int>(m));
    mat={{1, 1},{1, 1}};
    int maxi = 0;
    solve(n,m,0,0,mat,maxi);
    cout<<maxi;
    return 0;
}