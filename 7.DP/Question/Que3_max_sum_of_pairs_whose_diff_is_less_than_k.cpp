#include <bits/stdc++.h>
using namespace std;
int solve(int a[], int n, int k){
    sort(a,a+n);
    reverse(a,a+n);
    int i = 0;
    int sum = 0;
    while(i < n-1){
        int x = abs(a[i] - a[i+1]);
        if(x < k){
            sum += a[i];
            sum += a[i+1];
            i++;
        }
        else{
            i++;
        }
    }
    return sum;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
       cin>>a[i];
    }
    int k;
    cin>>k;
    cout<<solve(a,n,k);
    return 0;
}