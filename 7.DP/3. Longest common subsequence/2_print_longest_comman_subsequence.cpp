#include <bits/stdc++.h>
using namespace std;
string noLongestSub(string s1, string s2, int n, int m){ 
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
                dp[i][j] = 0;
            }
        }
    }
    // for printing longest subsequence
    int i=n , j=m;
    string s = "";
    while(i>=0 && j>=0){
        if(s1[n] == s2[m]){
            s += s1[i];
            i--;
            j--;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    reverse(s.begin(), s.end());
    return s;
}
int main(){
    string s1, s2;
    cin>>s1>>s2;
    int n = s1.length();
    int m = s2.length();
    cout<<noLongestSub(s1,s2, n, m);
    return 0;
}