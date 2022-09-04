#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, count=0;
    cin>>n;
    // Brian kernighan's Algo
    // while(n!=0){
    //     count++;
    //     n = n & (n-1);
    // }
    
    // Most optimize code ...(GFG)
     while(n!=0){
            if(n&1==1){
                count ++;
            }
            n=n>>1;
        }
    cout<<count;
    return 0;
}