// https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/description/

// first see the tabulation method, 
// Approach -> check dp[i][j] is depending on what?
// it is depending upon ans variable, and ans variable is depending upon dp[i+1][0] & dp[i+1][1];
// so replace dp[i+1][0] = noSwapp, dp[i+1][1] = Swapp;
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int>&num1, vector<int>&num2, int i, bool swapTrue){
    int n = num1.size();
    // vector<vector<int>>dp(n+1, vector<int>(2, 0)); removing 2d vector
    int noSwapp=0, Swapp=0;
    int currnoSwapp=0, currSwapp=0;
    for(int i=n-1; i>=1; i--){
        for(int j=1; j>=0; j--){
            int prev1 = num1[i-1];
            int prev2 = num2[i-1];
            if(j == 1){
                swap(prev1, prev2);
            }
            int ans = INT_MAX;
            if(num1[i]>prev1 && num2[i]>prev2){
                ans = noSwapp;
            }
            if(num1[i]>prev2 && num2[i]>prev1){
                int ansSwap = 1+Swapp;
                ans= min(ans,ansSwap);
            }
            // dp[i][j]= ans;
            if(j == 1){
                currSwapp = ans;
            }
            else{
                currnoSwapp = ans;
            }
        }
        noSwapp = currnoSwapp;
        Swapp = currSwapp;
    }
    return min(noSwapp, Swapp);
}
int main(){
    int n=10;
    vector<int>num1(n);
    vector<int>num2(n);
    num1={3,5,6,9,14,15,15,18,17,20};
    num2={3,4,5,8,10,14,17,16,19,19};

    // for taking 0th index under considerisation
    num1.insert(num1.begin(), -1);
    num2.insert(num2.begin(), -1);
    cout<<solve(num1,num2,1,0);
    return 0;
}