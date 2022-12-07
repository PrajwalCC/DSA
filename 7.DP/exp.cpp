#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int prev2=0, prev=1;
    int curr;
    for(int i=2; i<=n; i++){
        curr=prev2 + prev;
        prev2 = prev;
        prev = curr;
    }
    cout<<prev;
    return 0;
}