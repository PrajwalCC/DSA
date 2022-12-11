#include <bits/stdc++.h>
using namespace std;
int solve(int n, int cost[]){
  if(n==0){
    return cost[0];
  }
  if(n==1){
    return cost[1];
  }
  int ans = min(solve(n-1,cost), solve(n-2,cost)) + cost[n];
  return ans;
}
int main(){
    int n = 3;
    int cost[n]={10,15,20};
    cout<<min(solve(n-1,cost),solve(n-2,cost));
    return 0;
}