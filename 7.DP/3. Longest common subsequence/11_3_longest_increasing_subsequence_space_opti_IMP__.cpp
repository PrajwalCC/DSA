// resource -- Love babbar
#include <bits/stdc++.h>
using namespace std;
int solve(int a[],int n, int idx, int prev){

    // vector<vector<int>> dp(n+1, vector<int>(n+1, 0)); //replce with two 1D vector
    // replacement-> dp[i][j+1] = curr[j+1] , dp[i+1][j] = next[j]
    // we are just replacing dp[i] --> curr  & dp[i+1] --> next
    vector<int>curr(n+1);
    vector<int>next(n+1);
    for(int i=n-1; i>=0; i--){
        for(int j = i-1; j>= -1; j--){
            if(j == -1 || a[j] < a[i]){
                curr[j+1] = max(next[j+1], 1 + next[i+1]);
            }
            else{
                curr[j+1]  = next[j+1] ;
            }
        }
        next=curr;
    }
    return next[-1+1];
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
       cin>>a[i];
    }
    
    cout<<solve(a,n,0,-1);
    return 0;
}