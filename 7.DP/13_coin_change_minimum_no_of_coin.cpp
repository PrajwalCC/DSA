#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int coin[n];
    for(int i=0; i<n; i++){
       cin>>coin[i];
    }
    int sum;
    cin>>sum;
    cout<< allPossibleWaysOfSum(coin, n, sum);
    return 0;
}