// https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    // utility function
    long long add(int a, int b){
        return ((a%1000000007)+(b%1000000007))%1000000007;
    }
    long long mul(int a, int b){
        return ((a%1000000007)*1LL*(b%1000000007))%1000000007;
    }

    // code start here
    int solve(int n, int k, vector<int> &dp){
        if(n == 1){
            return dp[n] = k;
        }
        if(n == 2){
            return dp[n] = add(k,mul(k,k-1));
        }
        if(dp[n] != -1){
            return dp[n];
        }
        return dp[n] = mul(add(solve(n-2,k,dp), solve(n-1,k,dp)), k-1);
    }
    long long countWays(int n, int k){
        // code here
        vector<int> dp(n+1, -1);
        return solve(n,k,dp);
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends