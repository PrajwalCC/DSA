// we assume that solve func will give total no of ways
//one can go from ith stair to nth stair
#include <bits/stdc++.h>
using namespace std;
int solve(int n, int i){
    if(i==n){
        return 1;
    }
    if(i>n){
        return 0;
    }
    return solve(n, i+1) + solve(n, i+2);
}
int main(){
    int n;
    n=2;
    cout<<solve(n,0);
    return 0;
}