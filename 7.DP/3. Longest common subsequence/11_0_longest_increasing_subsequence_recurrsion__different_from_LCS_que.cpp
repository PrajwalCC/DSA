#include <bits/stdc++.h>
using namespace std;
int solve(int a[],int n, int idx, int prev){
    if(idx == n){
        return 0;
    }
    if(prev == -1 || a[prev] < a[idx]){
        return max(solve(a,n,idx+1,prev), 1+solve(a,n,idx+1, idx));
    }
    else{
        return solve(a,n,idx+1,prev);
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
       cin>>a[i];
    }
    cout<<solve(a,n,0,-1);
    return 0;
}