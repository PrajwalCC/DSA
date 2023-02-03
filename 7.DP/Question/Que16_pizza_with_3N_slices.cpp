// Similar Like -- House Robbery Problem Leetcode
// https://leetcode.com/problems/pizza-with-3n-slices/description/
#include <bits/stdc++.h>
using namespace std;
// recurrsion
// int solve(vector<int> s, int n, int i, int k){
//     if(i >= n || k == 0){
//         return 0;
//     }
//     int included = s[i] + solve(s,n,i+2, k-1);
//     int excluded = solve(s,n,i+1,k);
//     return max(included,excluded);
// }

// Tabulation
int solve(vector<int> s, int n, int i, int k){
    vector<vector<int>>dp(n+2, vector<int>(k+1));
    for(int i=0; i< n+2; i++){
        for(int j=0; j <= k; j++){
            if(i >= n){
                dp[i][j]=0;
            }
            if(j == 0){
                dp[i][j] = 0;
            }
        }
    }
    for(int i=n-1; i>=0; i--){
        for(int j=1; j <= k; j++){
            
            int included = s[i] + dp[i+2][j-1];
            int excluded = dp[i+1][j];
            dp[i][j] = max(included,excluded);
        }
    }
    return dp[0][k];
}

int main(){
    vector<int> slices(6);
    vector<int> first,last;
    // slices = {1,2,3,4,5,6};
    slices[0]=1;
    slices[1]=2;
    slices[2]=3;
    slices[3]=4;
    slices[4]=5;
    slices[5]=6;
    int n = slices.size();
    for(int i=0; i<n ; i++){
        if(i == 0){
            first.push_back(slices[i]);
            continue;
        }
        if(i == n-1){
            last.push_back(slices[i]);
            continue;
        }
        first.push_back(slices[i]);
        last.push_back(slices[i]);
    }
    cout<<max(solve(first,n-1,0,n/3), solve(last,n-1,0,n/3));
    return 0;
}