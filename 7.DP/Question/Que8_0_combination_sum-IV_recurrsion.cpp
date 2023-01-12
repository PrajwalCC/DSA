// https://leetcode.com/problems/combination-sum-iv/description/
// resource -- striver
#include <bits/stdc++.h>
using namespace std;
int solve(int a[], int n, int sum){
    if(sum == 0){
        return 1;
    }
    if(sum < 0){
        return 0;
    }
    int ans =0;
    for(int i=0; i<n; i++){
        ans += solve(a,n,sum-a[i]);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int sum ;
    cin>>sum;
    cout<<solve(a,n,sum);
    return 0;
}