// https://leetcode.com/problems/minimum-sideway-jumps/description/
// resource -> love babbar
#include <bits/stdc++.h>
using namespace std;
int solve(int obstacle[],int  n){
    vector<int>next(4,INT_MAX);
    vector<int>curr(4,INT_MAX);
    next[0]=0;
    next[1]=0;
    next[2]=0;
    next[3]=0;
    for(int j=n-1; j>=0; j--){
        for(int i=3; i>=0; i--){
            if(obstacle[j+1] == i){
                int ans = INT_MAX;
                for(int k=1; k<=3; k++){
                    if(i != k && obstacle[j] != k){
                        ans = min(ans, 1+next[k]);
                    }
                }
                curr[i]=ans;
            }
            else{
                curr[i]= next[i];
            }
        }
        next=curr;
    }
    return min(next[2],  min(1+next[1], 1+next[3]));
}
int main(){
    int n;
    cin>>n;
    int obstacle[n];
    for(int i=0; i<n; i++){
        cin>>obstacle[i];
    }
    cout<<solve(obstacle,n);
    return 0;
}