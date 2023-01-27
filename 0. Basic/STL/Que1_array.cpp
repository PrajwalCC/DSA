// question -> 6 4 1 2 7
// answer   -> 3 2 0 1 4
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    int temp[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
        temp[i]=a[i];
    }
    sort(a,a+n);
    map<int,int> m;
    for(int i=0; i<n; i++){
        m[a[i]]=i;
    }
    int ans[n];
    for(int i=0; i<n; i++){
        auto it = m.find(temp[i]);
        ans[i] = (*it).second;
    }
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }


    return 0;
}