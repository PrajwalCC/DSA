#include <bits/stdc++.h>
using namespace std;
string noLongestSub(string s1, int n){
    string s2 = s1;
    int m = n;

    // for debuging 
    string s = "";
    
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
            if(s1[i-1] == s2[j-1] && (i != j)){
                dp[i][j] =  dp[i-1][j-1] + s1[i-1];
                s+=s1[i-1];
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
    cout<<s<<endl;
    return dp[n][m];
}
int main(){
    string s1;
    cin>>s1;
    int n = s1.length();
    cout<<noLongestSub(s1, n);
    return 0;
}