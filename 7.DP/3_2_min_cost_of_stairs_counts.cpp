#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &dp, int n, int cost[]){
    int prev2=cost[0];
    int prev1=cost[1];
    for(int i=2; i<n; i++){
        int curr = min(prev1,prev2)+cost[i];
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int main(){
    int n=3;
    int cost[n]={10,15,20};
    vector<int> dp(n+1, -1);
    // cout<<min(solve(dp,n-1,cost),solve(dp,n-2,cost));
    cout<<min(solve(dp,n-1,cost),solve(dp,n-2,cost));
    return 0;
}