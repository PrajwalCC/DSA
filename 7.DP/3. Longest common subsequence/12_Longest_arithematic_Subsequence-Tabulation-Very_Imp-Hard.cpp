#include <bits/stdc++.h>
using namespace std;
int solve(int a[], int n){
    if(n<=2){
        return n;
    }
    int ans=0;
    unordered_map<int,int> dp[n+1];

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            int diff = a[i]-a[j];
            int count=1;

            // check if ans already present
            if(dp[j].count(diff)){
                count=dp[j][diff];
            }
            dp[i][diff] = 1+count;
            ans = max(ans, dp[i][diff]);
        }
    }
    return ans;
}
int main(){
    int n = 6;
    int a[n]={1, 7, 10, 13, 14, 19};
    cout<<solve(a,n);
    return 0;
}