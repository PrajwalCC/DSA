// https://practice.geeksforgeeks.org/problems/7a33c749a79327b2889d420dd80342fff33aac6d/1
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int solve(vector<int> a, int n, int j){
	    vector<int>dp(n+2, 0);
	   for(int i=n-1; i>=0; i--){
	       dp[i]= max(a[i]+dp[i+2], dp[i+1]);
	   }
	   return dp[0];
	    
	}
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int> a(n);
	    for(int i=0; i<n; i++){
	        a[i]=arr[i];
	    }
	    return solve(a,n,0);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends