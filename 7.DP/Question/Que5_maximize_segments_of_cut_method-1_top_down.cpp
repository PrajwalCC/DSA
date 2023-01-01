#include <bits/stdc++.h>
using namespace std;
int solve(int n, int x, int y, int z, vector<int>dp){
    int a = INT_MIN,b=a,c=a;
    if(n==0){
        return dp[n] = 0;
    }
    
    if(dp[n] != -1){
        return dp[n];
    }

    if(n >= x){
        a = solve(n-x,x,y,z, dp)+1;
    }
    if(n >= y){
        b = solve(n-y,x,y,z, dp)+1;
    }
    if(n >= z){
        c = solve(n-z,x,y,z, dp)+1;
    }
    
    return dp[n] = max(a,max(b,c));
}

int main(){
    int n;
    cin>>n;
    int x,y,z;
    cin>>x>>y>>z;
    vector<int> dp(n+1, -1);
    cout<<solve(n,x,y,z, dp);
    return 0;
}