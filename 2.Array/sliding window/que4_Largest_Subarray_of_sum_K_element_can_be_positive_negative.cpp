// https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
// striver video
// topic= sliding , prefix sum, map
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cin>>k;
    map<int,int> m;
    int sum = 0, maxLen=0;
    for(int i=0; i<n; i++){
        sum += a[i];
        if(sum == k){
            maxLen = max(maxLen, i+1);
        }
        int check = sum - k;
        
        if(m.find(check) != m.end()){
            maxLen = max(maxLen, i-m[check]);
        }
        
        if(m.find(sum) == m.end()){
            m[sum]=i;
        }
    }
    cout<<maxLen;
    return 0;
}