#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n;i++){
        cin>>a[i];
    }

    const int N = 2e5;
    int idx[N];

    for(int i=0; i<N; i++){

       idx[i]=-1;
    }

    int minIdx= INT_MAX;

    for(int i=0; i<n; i++){
        if(idx[a[i]]== -1){
             idx[a[i]] = i;
        }
        else{

            minIdx = min(minIdx,idx[a[i]]);
        }
    }
    
    if(minIdx== INT_MAX){
        cout<<-1;
    }
    else{
        cout<<minIdx + 1 ;
    }

    return 0;
}