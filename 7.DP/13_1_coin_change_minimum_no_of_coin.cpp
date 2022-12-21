#include <bits/stdc++.h>
using namespace std;
int checkSum(vector<int> arr, int sum, int** dp, vector<int> min){
    int n = arr.size();
    if(n==0){
        return 0;
    }
    if(sum==0){
        return 1;
    }

    if(dp[n][sum] != -1){
        return dp[n][sum];
    }

    if(arr[n-1] <= sum){
        int temp = arr[n-1];
        int temp1 = checkSum(arr, sum-temp,dp, min);
        arr.pop_back();
        int temp2 = checkSum(arr, sum,dp,min);
        dp[n][sum] = temp1 + temp2 ;
        return dp[n][sum];
    }
    else{
        arr.pop_back();
        // cout<<dp[n][sum]<<" ";
        return dp[n][sum] = checkSum(arr, sum,dp,min);
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
    vector<int> min;
    cout<<checkSum(arr,sum,dp,min);
    return 0;
}