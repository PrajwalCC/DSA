#include <bits/stdc++.h>
using namespace std;
bool checkSum(vector<int> arr, int sum, int** dp){
    int n = arr.size();
    if(n==0){
        // cout<<dp[n][sum]<<" ";
        return false;
    }
    if(sum==0){
        // cout<<dp[n][sum]<<" ";
        return true;
    }

    if(dp[n][sum] != -1){
        // cout<<dp[n][sum]<<"---";
        return dp[n][sum];
    }

    if(arr[n-1] <= sum){
        int temp = arr[n-1];
        arr.pop_back();
        dp[n][sum] = checkSum(arr, sum-temp,dp) || checkSum(arr, sum,dp) ;
        // cout<<dp[n][sum]<<" ";
        return dp[n][sum];
    }
    else{
        arr.pop_back();
        // cout<<dp[n][sum]<<" ";
        return dp[n][sum] = checkSum(arr, sum,dp);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0; i<n; i++){
       int temp;
       cin>>temp;
       arr.push_back(temp);
    }
    int sum;
    cin>>sum;

    int** dp;
    dp = new int*[n+1];
    for (int i = 0; i <= n; i++){
        dp[i] = new int[sum + 1];
    }

    for(int i=0; i<=n;i++){
        for(int j=0; j<=sum;j++){
            dp[i][j]=-1;
        }
    }    
    
    cout<<checkSum(arr,sum,dp);
    return 0;
}