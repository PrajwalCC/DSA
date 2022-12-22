// it is same as 0/1 unbounded knapsack

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int unboundedKnapsack(int w[], int v[], int weight, int n){
        vector<vector<int> > dp(n + 1, vector<int>(weight + 1));
    
        for(int i=0; i<=n;i++){
            for(int j=0; j<=weight;j++){
                if(n==0 || weight==0){
                    dp[i][j]=0;
                }
            }
        }
        for(int i=1; i<=n;i++){
            for(int j=1; j<=weight;j++){
                // if(n==0 || w==0){
                //     dp[i][j]=0;
                // }
                
                if(w[i-1] <= j){
                    dp[i][j] = max(v[i-1]+dp[i][j-w[i-1]] , dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
                
            }
        }
        return dp[n][weight];
    }
    int cutRod(int price[], int n) {
        //code here
        int length[n];
        for(int i=0; i<n ;i++){
            length[i]=i+1;
        }
        return unboundedKnapsack(length,price,n,n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends