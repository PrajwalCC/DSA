#include <bits/stdc++.h>
using namespace std;
string noLongestSub(string s1, string s2, int n, int m){ 
    vector<vector<string>>dp(n+1, vector<string>(m+1));
    for(int i=0; i<= n; i++){
        for(int j=0; j<= m; j++){
            if(n==0 || m==0){
                dp[i][j] = "";
            }
        }
    }
    for(int i=1; i<= n; i++){
        for(int j=1; j<= m; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1]+s1[i-1];
            }
            else{
                if(dp[i-1][j].length() > dp[i][j-1].length()){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
    }
    // for printing longest subsequence
    return dp[n][m];
}
int main(){
    string s1, s2;
    cin>>s1>>s2;
    int n = s1.length();
    int m = s2.length();
    cout<<noLongestSub(s1,s2, n, m);
    return 0;
}