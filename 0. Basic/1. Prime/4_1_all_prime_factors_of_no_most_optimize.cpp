#include <bits/stdc++.h>
using namespace std;
long long n = 1000000;
// int spf[n+1];
vector<int> spf;

void createSieve(){
    for(long long i=0; i<=n ; i++){
        // spf[i]=i;
        spf.push_back(i);
    }
    for(long long i=2; i*i<=n; i++){
        if(spf[i]==i){
            for(long long j=i*i; j<=n; j=j+i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }
}
int main(){
    
    // T.C = O(n log (log n))
    createSieve();
    int p=36;

    // T.C = O(logn)
    while(p != 1){
        cout<<spf[p]<<" ";
        p=p/spf[p];
    }
    return 0;
}