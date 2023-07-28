#include <bits/stdc++.h>
using namespace std;
int noLongestSub(string s1, int n){
    string s2 = s1;
    int m = n;
    vector<vector<int>>dp(n+1, vector<int>(m+1));
    for(int i=0; i<= n; i++){
        for(int j=0; j<= m; j++){
            if(n==0 || m==0){
                dp[i][j] = 0;
            }
        }
    }
    for(int i=1; i<= n; i++){
        for(int j=1; j<= m; j++){
            if(s1[i-1] == s2[j-1] && (i != j)){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
int main(){
    string s1;
    cin>>s1;
    int n = s1.length();
    cout<<noLongestSub(s1, n);
    return 0;
}