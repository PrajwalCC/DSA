#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n], b[n],max=0, ans=0;
    for(int i=0; i<n;i++){
        cin>>a[i];
        
        if(a[i]>max){
            max=a[i];
        }

        b[i]=max;
    }
    
    for(int i=0; i<n-1; i++){
       if(a[i]==b[i] && a[i]> a[i+1]){
        ans++;
       }
    }

    if(a[n-1]==b[n-1]){
          ans++;
    }

   cout<<ans;

    return 0;
}