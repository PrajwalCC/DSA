// in input one string is given, we have to find longest panlindromic subsequence
// this que is similar to LCS, try to convert it in that approach
// ~~~ s1 = s , s2 = reverse of s 
//     LCS of s1 and s2 is equal to LPS(Longest panlindromic subsequence) of s.
#include <bits/stdc++.h>
using namespace std;
int longestPalindromicSubsequence(string s){
    string s1=s;
    reverse(s.begin(), s.end());
    string s2=s;
    int n=s1.length();
    int m=s2.length();

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
            if(s1[i-1] == s2[j-1]){
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
    string s;
    cin>>s;
    cout<<longestPalindromicSubsequence(s);
    return 0;
}