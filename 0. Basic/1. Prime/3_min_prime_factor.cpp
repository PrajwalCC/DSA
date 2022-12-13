// In a range of 0 to 10, find n is min prime factor of how many no. 
// example, in range of 0 to 10... 2 is min prime factor of 2,4,6,8,10
// 3 is min prime factor of 3,9 but not 6 becoz min prime factor of 6 is 2
// so we have create sieve vector like hash map , index of sieve vector will tell us that index no. is min prime factor for how many no. in range of 0 to 10.
#include <bits/stdc++.h>
using namespace std;
int n = 10;
vector<int> sieve(n+1, 1);
void totalNoMinPrime(){
    sieve[0]=0;
    sieve[1]=0;
    for(int i=2; i*i<=n; i++){
        if(sieve[i]>0){
           for(int j= i*i; j<=n; j=j+i){
               if(sieve[j] != 0){
                 sieve[j]=0;
                 sieve[i]++;
               }
           }
        }
    }
}
int main(){
    totalNoMinPrime();
    int p=2;
    cout<<"how many no. in range 0 to 10 has min prime factor of "<<p<<" = ";
    cout<<sieve[2];
    return 0;
}