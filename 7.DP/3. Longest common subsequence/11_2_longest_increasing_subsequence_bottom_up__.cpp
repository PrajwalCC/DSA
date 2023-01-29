// resource -- striver
// Time comp - n^2 
// there is another as tabulation , striver dp series 42th video refer that from that method he has tell how 
// print LIS that method complexicity is n^2 ..

#include <bits/stdc++.h>
using namespace std;
int solve(int a[],int n, int idx, int prev){
    // flow of code, from back of array...
    // since we have taken prev as -1 also thats we have shifted ordinate of j in dp[i][j+1]

    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int i=n-1; i>=0; i--){
        for(int j = i-1; j>= -1; j-- ){
            if(j == -1 || a[j] < a[i]){
                dp[i][j+1] = max(dp[i+1][j+1], 1 + dp[i+1][i+1]);//dp[i+1][i+1] here i+1 is there becoz of coordinate shift
            }
            else{
                dp[i][j+1]  = dp[i+1][j+1] ;
            }
        }
    }
    for(int i=0; i<= n; i++){
        for(int j=-1; j<= i-1; j++){
            cout<<dp[i][j+1]<<" ";
        }
        cout<<endl;
    }
    return dp[0][-1+1];
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
       cin>>a[i];
    }
    
    cout<<solve(a,n,0,-1);
    return 0;
}