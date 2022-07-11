#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n], b[n-1], max=1, same=1;
    for(int i=0; i<n;i++){
        cin>>a[i];
    }

    for(int i=0; i<n-1;i++){
        b[i]=a[i]-a[i+1];
    }
    
    for(int i=0; i<n-2; i++){
        if(b[i]==b[i+1]){
            same++;
        }
        else{
            same=1;
        }

        if(same>max){
            max=same;
        }

    }
    
   cout<<max+1;
    
    return 0;
}