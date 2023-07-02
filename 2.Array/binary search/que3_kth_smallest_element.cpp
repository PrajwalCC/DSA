#include <bits/stdc++.h>
using namespace std;
int count(int a[], int n, int x){
    int i=0,j=1, total=0;
    while(i<=j){
        if(i==n){
            break;
        }
        int diff = a[j]-a[i];
        if(diff <= x){
            total++;
            if(j<n){
                j++;
            }
            else{
                i++;
            }
        }
        else{
            i++;
        }
    }
    return total;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cout<<count(a,n,1);
    return 0;
}