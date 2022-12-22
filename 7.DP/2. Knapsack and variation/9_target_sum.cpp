// Given an array of integers A[] of length N and an integer target.
// You want to build an expression out of A by adding one of the symbols '+' and '-' before each integer in A and then concatenate all the integers.
#include <bits/stdc++.h>
using namespace std;
vector<int> subsetSum(vector<int> arr, int n, int x){
    vector<vector<int>>dp(n+1, vector<int>(x+1));
    for(int i=0; i<=n; i++){
        for(int j=0; j<= x; j++){
            if(i==0){
                dp[i][j]=0;
            }
            if(j==0){
                dp[i][j]=1;
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=0; j<= x; j++){          
            if(arr[i-1] <= j){
                int temp = arr[i-1];
                dp[i][j] = dp[i-1][j-temp] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    vector<int> ans;
    for(int j=0; j<= x; j++){
        ans.push_back(dp[n][j]);
    }
    return ans;
}
int findTargetSumWays(vector<int>&a ,int target) {
    //Your code here
    int n= a.size();
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=a[i];
    }

    vector<int> ans = subsetSum(a,n,sum);
    for(int j=0; j<= sum; j++){
        if(ans[j] != 0){
            if(target == sum - (2*j)){
                return ans[j];
            }
        }
    }
    return 0;
}
int main(){
    int n;
    cin >> n;
   	vector<int> a;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        a.push_back(temp);
    }
    int target;
    cin>>target;
    cout<<findTargetSumWays(a,target);
    return 0;
}