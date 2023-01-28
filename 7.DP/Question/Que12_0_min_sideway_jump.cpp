// https://leetcode.com/problems/minimum-sideway-jumps/description/
// resource-- love babbar
#include <bits/stdc++.h>
using namespace std;
int solve(int obstacle[],int  n, int currLane, int currPosition){
    if(currPosition == n){
        return 0;
    }
    
    if(obstacle[currPosition+1] == currLane){
        int ans = INT_MAX;
        for(int i=1; i<=3; i++){
            if(currLane != i && obstacle[currPosition] != i){
                ans = min(ans, 1+solve(obstacle,n,i,currPosition));
            }
        }
        return ans;
    }
    else{
        return solve(obstacle,n,currLane,currPosition+1);
    }
}
int main(){
    int n;
    cin>>n;
    int obstacle[n];
    for(int i=0; i<n; i++){
        cin>>obstacle[i];
    }
    n=n-1;//mention in question
    cout<<solve(obstacle,n,2,0);
    return 0;
}