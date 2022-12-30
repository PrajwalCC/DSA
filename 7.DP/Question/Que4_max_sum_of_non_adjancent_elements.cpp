#include <bits/stdc++.h>
using namespace std;
int count(int amount[], int n, int ans){
    // recurrsion code
//    if(n == 1){
//     return max(amount[0], amount[1]);
//    }
//    if(n == 0 ){
//     return amount[0];
//    }

//    ans += max(count(amount,n-1,ans), amount[n]+count(amount,n-2,ans));
//    return ans;

// bottom up
   vector<int>dp(n+1);
   dp[0] = 0;

   for(int i=1; i<=n ; i++){
        if(i == 1){
            dp[i] = amount[i-1];
        }
        else{
            dp[i] = max(dp[i-1], amount[i-1]+dp[i-2]);
        }
   }
   return dp[n];

//    space optimizisation
    // int prev1 = 0;
    // int prev2 = 0;
    // int curr = 0;
    // for(int i=1; i<=n; i++){
        
    //     int included = prev2+ amount[i-1];
    //     int excluded = prev1;
    //     curr  = max(excluded , included);
    //     prev2 = prev1;
    //     prev1 = curr;
    // }
    // return curr;
}
int main(){
    int n;
    cin>>n;
    int amount[n];
    for(int i=0; i<n; i++){
        cin>>amount[i];
    }
    cout<<count(amount,n,0);
    return 0;
}