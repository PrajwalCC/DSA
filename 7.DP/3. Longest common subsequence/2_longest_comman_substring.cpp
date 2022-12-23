#include <bits/stdc++.h>
using namespace std;
int noLongestSub(string s1, string s2, int n, int m){ 
    vector<vector<int>>dp(n+1, vector<int>(m+1));
    int result=0;
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
                result=max(result, dp[i][j]);
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    
    return result;
}
int main(){
    string s1, s2;
    cin>>s1>>s2;
    int n = s1.length();
    int m = s2.length();
    cout<<noLongestSub(s1,s2, n, m);
    return 0;
}