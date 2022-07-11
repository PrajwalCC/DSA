#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n], b[n], max=0;
    for(int i=0; i<n;i++){
        cin>>a[i];
      if(a[i]>max){
        max=a[i];
      }
        b[i]=max;
    }
    
    for(int i=0; i<n; i++){
        cout<<b[i]<<" ";
    }

    return 0;
}