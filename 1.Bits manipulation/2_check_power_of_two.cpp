#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans = n & (n-1);
    if(ans==0){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }

    // if its binary representation contains only one 1 .. then its power of 2
    // int count =0;
    // while(n!=0){
    //     if(n&1 == 1){
    //         count++;
    //     }
    //     n = n>>1; 
    // }

    // if(count==1){
    //     cout<<"Yes";
    // }
    // else{
    //     cout<<"No";
    // }
    return 0;
}