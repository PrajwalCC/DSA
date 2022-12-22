#include <bits/stdc++.h>
using namespace std;
int perfectSum(vector<int> arr,int n, int sum){
    vector<vector<int>> dp(n+1, vector<int>(sum+1));
    for(int i=0; i<=n ;i++){
        for(int j=0; j<=sum; j++){
            if(i==0){
                dp[i][j] = 0;
            }
            if(j==0){
                dp[i][j] = 1;
            }
        }
    }
    //in below loop if j is started from 1 then ans is not coming and if j is started from 0 then ans is comming  
    for(int i=1; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}
int main(){
    int n;
    cin>>n;
    vector<int> arr;
    int sum;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    cin>>sum;
    cout<<perfectSum(arr,n,sum);
    return 0;
}