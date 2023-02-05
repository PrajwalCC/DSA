// https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/description/
// Love babbar
// resource = https://www.youtube.com/watch?v=IeT9Qz_vqHo&list=PLDzeHZWIZsTomOPnCiU3J95WufjE36wsb&index=23

// My Mistake --> while swaping I was swaping array elements itself, so while backtracking array was disturbed
// Correction --> Instead swaping array elements , swap variables so that array will remain as it was before..while backtracking there will no problem occur
#include <bits/stdc++.h>
using namespace std;
// Recurrsion
// int solve(vector<int>&num1, vector<int>&num2, int i, bool swapTrue){
//     if(i == num1.size()){
//         return 0;
//     }
//     int prev1 = num1[i-1];
//     int prev2 = num2[i-1];
//     if(swapTrue){
//         swap(prev1, prev2);
//     }
//     int ans = INT_MAX;
//     if(num1[i]>prev1 && num2[i]>prev2){
//         // no swapping
//         ans = solve(num1,num2,i+1,0);
//     }
//     if(num1[i]>prev2 && num2[i]>prev1){
//         // swapping
//         int ansSwap = 1+solve(num1,num2,i+1,1);
//         ans = min(ans,ansSwap);
//     }
//     return ans;
// }
int solve(vector<int>&num1, vector<int>&num2, int i, bool swapTrue){
    int n = num1.size();
    vector<vector<int>>dp(n+1, vector<int>(2, 0));
    // ### alert ---> here i goes till 1 not 0
    for(int i=n-1; i>=1; i--){
        for(int j=1; j>=0; j--){
            int prev1 = num1[i-1];
            int prev2 = num2[i-1];
            if(j == 1){
                swap(prev1, prev2);
            }
            int ans = INT_MAX;
            if(num1[i]>prev1 && num2[i]>prev2){
                ans = dp[i+1][0];
            }
            if(num1[i]>prev2 && num2[i]>prev1){
                int ansSwap = 1+dp[i+1][1];
                ans= min(ans,ansSwap);
            }
            dp[i][j]= ans;
        }
    }
    return dp[1][0];//we have insert -1 at 0th position, original array start from 1st index
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