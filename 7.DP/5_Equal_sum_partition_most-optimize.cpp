// Que -> check if array can be partitioned into two parts such that the sum of elements in both parts is the same
// best logic -> int sum = sum of all element of array
// sum1 = sum/2;
// now we will find subset from given array whose sum is equal to sum1.. if such exit then partition is possible 
// ---->Find sum of all elements in array, divide it by 2, 
// Use another dp problem subset sum to check whether this (sum/2) can be generated or not.
#include <bits/stdc++.h>
using namespace std;
bool checkEqual(vector<int> arr, int sum){
    int n = arr.size();
    vector<vector<bool>> dp(n+1, vector<bool>(sum+1));
    for(int i=0; i<=n ;i++){
        for(int j=0; j<=sum; j++){
            if(i==0){
                dp[i][j] = false;
            }
            if(j==0){
                dp[i][j] = true;
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
    return dp[n][sum];
}
int main(){
    int n;
    cin>>n;
    vector<int> arr;
    int sum=0;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
        sum+=temp;
    }
    if(sum % 2 != 0){
        cout<<"Not possible";
        return 0;
    }
    else{
        sum=sum/2;
        cout<<checkEqual(arr,sum);
    }
    return 0;
}