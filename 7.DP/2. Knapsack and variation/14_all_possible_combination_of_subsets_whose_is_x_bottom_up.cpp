// https://leetcode.com/problems/combination-sum-iv/description/
#include <bits/stdc++.h>
using namespace std;
int solve(int a[], int n, int sum){
    vector<int> dp(sum+1, 0);
    dp[0] = 1;
    int ans ;
    for(int i=1; i<=sum; i++){
        ans =0;
        for(int j=0; j<n; j++){
            if(i-a[j] >= 0){
                ans += dp[i-a[j]];
            }
        }
        dp[i] = ans;
    }
    return dp[sum];
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int sum ;
    cin>>sum;
    cout<<solve(a,n,sum);
    return 0;
}