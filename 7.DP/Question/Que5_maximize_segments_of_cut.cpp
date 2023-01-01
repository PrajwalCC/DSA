#include <bits/stdc++.h>
using namespace std;
int solve(int n, vector<int> v, int i, vector<int>& dp){
    
    if(i == v.size()){
        return 0;
    }
    if(n == 0){
        return dp[n]=0;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int pick, notPick;
    if(n >= v[i]){
       pick = solve(n-v[i],v,i, dp) + 1;
       notPick = solve(n,v,i+1, dp);
    }
    else{
        return INT_MIN;
    }
    return dp[n]= max(pick, notPick);

}

int main(){
    int n;
    cin>>n;
    int x,y,z;
    cin>>x>>y>>z;
    vector<int> v;
    v.push_back(x);
    v.push_back(y);
    v.push_back(z);
    sort(v.begin(), v.end());
    vector<int> dp(n+1, -1);
    int ans = solve(n,v,0, dp);
    if(ans<0){
        cout<< 0;
    }
    else{
        cout<<ans;
    }

    return 0;
}