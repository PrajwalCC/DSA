// T.C = O(nloglog(n))

#include <bits/stdc++.h>
using namespace std;

long long n = 10000000;
vector<bool> sieve(n+1, true);  
void checkPrime(){
    sieve[0]=false;
    sieve[1]=false;
    for(int i=2; i*i<=n; i++){
        if(sieve[i] == true){
            for(int j=i*i; j<=n; j=j+i){
                sieve[j]=false;
            }
        }
    }
}

int main(){
    checkPrime();
    int p=5;
    if(sieve[p]==true){
        cout<<"Yes it is prime";
    }else{
        cout<<"Not prime";
    }
    return 0;
}