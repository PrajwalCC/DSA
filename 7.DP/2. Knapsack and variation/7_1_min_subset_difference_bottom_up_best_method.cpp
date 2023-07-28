#include <bits/stdc++.h>
using namespace std;

vector<int> subsetSum(vector<int> arr, int sum){
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int>(sum + 1));
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
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    vector<int> ans;
    for(int j=0; j<=sum; j++){
        ans.push_back(dp[n][j]);
    }
    return ans;
}
int minDifference(int arr[], int n)  { 
    // Your code goes here
    int sum1=0;
    vector<int> v;
    for(int i=0; i<n; i++){
        sum1 += arr[i];
        v.push_back(arr[i]);
    }
    
    vector<int> ans = subsetSum(v,sum1);
    int mn = INT_MAX;
    for(int j=0; j<=(sum1/2); j++){
        if(ans[j] == 1){
            int temp = sum1-(2*j);
            mn = min(mn , temp);
        }
    }
    return mn;
} 

int main() 
{
   
    int n;
    cin >> n;
   	int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cout<<minDifference(a,n);
    return 0;
}
