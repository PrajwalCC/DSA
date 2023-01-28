// https://leetcode.com/problems/reducing-dishes/
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> s){
    int n = s.size();
    // vector<vector<int>>dp(n+1, vector<int>(n+1));
    vector<int>next(n+1);
    vector<int>curr(n+1);
    for(int i=0; i<=n; i++){
        for(int t=0; t<=n; t++){
            if(i==n){
               next[t]=0;
            }
        }
    }
    for(int i=n-1; i>=0; i--){
        for(int t=n-1; t>=0; t--){
            int included = s[i]*(t+1) + next[t+1];
            int excluded = next[t];
            curr[t]=max(included, excluded);
        }
        next = curr;
    }
    return next[0];
}
int main(){
    int n;
    cin>>n;
    vector<int>s(n);
    for(int i=0; i<n; i++){
        cin>>s[i];
    }
    cout<<solve(s);
    return 0;
}
