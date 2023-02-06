// https://practice.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1
// resource - love babbar
// https://www.youtube.com/watch?v=YaMcX7sem70&list=PLDzeHZWIZsTomOPnCiU3J95WufjE36wsb&index=24
#include <bits/stdc++.h>
using namespace std;
int solve(int a[], int n, int i, int diff){
    if(i < 0){
        return 0;
    }
    int ans =0; 
    for(int k=i-1; k>=0; k--){
        if(a[i]-a[k] == diff){
            ans = max(ans, 1+solve(a,n,k,diff));
        }
    }
    return ans;
}
int main(){
    int n = 6;
    int a[n]={1, 7, 10, 13, 14, 19};
    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int diff = a[j]-a[i];
            ans = max(ans, 2 + solve(a,n,i,diff));
        }
    }
    cout<<ans;
    return 0;
}