#include <bits/stdc++.h>
using namespace std;
bool checkSum(vector<int> arr, int sum){
    int n = arr.size();
    bool** dp;
    dp = new bool*[n+1];
    for (int i = 0; i <= n; i++){
        dp[i] = new bool[sum + 1];
    } 

    // vector<vector<bool>>dp(n+1, vector<bool>(sum+1));

    for(int i=0; i<=n; i++){
        for(int j=0; j<= sum; j++){
            if(i==0){
                dp[i][j]=false;
            }
            if(j==0){
                dp[i][j]=true;
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<= sum; j++){          
            if(arr[i-1] <= j){
                int temp = arr[i-1];
                dp[i][j] = dp[i-1][j-temp] || dp[i-1][j];
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
    for(int i=0; i<n; i++){
       int temp;
       cin>>temp;
       arr.push_back(temp);
    }
    int sum;
    cin>>sum;

    cout<<checkSum(arr,sum);
    return 0;
}