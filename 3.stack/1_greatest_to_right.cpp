#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n], ans[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    stack<int> s;
    for(int i=n-1; i>=0; i--){
        while((s.size() != 0) && s.top()<a[i]){
            s.pop();
        }
        if(s.size()==0){
            ans[i] = -1;
        }
        else if(s.top() > a[i]){
            ans[i] = s.top();
        }
        s.push(a[i]);
    }
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}