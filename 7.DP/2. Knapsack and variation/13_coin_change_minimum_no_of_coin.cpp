// subset sum + unbounded knapsack + twist in tabulation method .. we have to fill table for n=1 as a base condition

#include <bits/stdc++.h>
using namespace std;

int minCoins(int coin[], int n, int sum) { 

	vector<vector<int>>dp(n+1, vector<int>(sum+1));
	for(int i=0; i<= n; i++ ){
		for(int j=0; j<= sum; j++ ){
			if(i==0){
				dp[i][j]=INT_MAX - 1;
			}
			if(j==0){
				dp[i][j]=0;
			}
		}
	}
	// base condition for n=1 --> Twist 
	for(int j=1; j<= sum; j++ ){
		if(j % coin[0] == 0){
			dp[1][j]= j/coin[0];
		}
		else{
			dp[1][j]= INT_MAX-1;
		}
	}
	for(int i=2; i<= n; i++ ){
		for(int j=1; j<= sum; j++ ){
			if(coin[i-1] <= j){
				dp[i][j] = min(dp[i][j-coin[i-1]] + 1 , dp[i-1][j]);
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return (dp[n][sum]==INT_MAX-1?-1:dp[n][sum]);
} 

int main() 
{
   	int n;
    cin>>n;
    int coin[n];
    for(int i=0; i<n; i++){
       cin>>coin[i];
    }
    int sum;
    cin>>sum;
	cout<< minCoins(coin, n, sum);
    return 0;
}

