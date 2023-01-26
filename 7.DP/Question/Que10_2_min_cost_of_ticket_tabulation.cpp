#include <bits/stdc++.h>
using namespace std;
int solve(int day[], int cost[], int i, int n){
    vector<int>dp(n+1, INT_MAX);
    dp[n]=0;
    for(int j = n-1; j>=0; j--){
        // for 1 day
        int a = dp[j+1] + cost[0];
        // for 7days
        int temp = day[j];
        int index;
        for(int k=i; k<n; k++){
            if(day[k] > temp+6){
                index = k;
            break;
            }
            index = k+1;
        }
        int b = dp[index]+cost[1];
        // for 30days
        temp = day[j];
        for(int k=i; k<n; k++){
            if(day[k] > temp+29){
                index = k;
            break;
            }
            index = k+1;
        }
        int c = dp[index]+cost[2];
        dp[j]=min(a,min(b,c));
    }
    return dp[0];
}
int main(){
    int n;
    cin>>n;
    int day[n];
    for(int i=0; i<n; i++){
        cin>>day[i];
    }
    int cost[3];
    for(int i=0; i<3; i++){
        cin>>cost[i];
    }
    cout<<solve(day,cost,0,n);
    return 0;
}