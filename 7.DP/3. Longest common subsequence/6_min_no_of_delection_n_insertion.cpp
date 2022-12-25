// ***QUE- Given two strings str1 and str2. The task is to remove or insert the minimum number of characters from/in str1 so as to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.
// 
// ***EXAMPLE-Input: str1 = "heap", str2 = "pea"
// Output: 3
// Explanation: 2 deletions and 1 insertion
// p and h deleted from heap. Then, p is 
// inserted at the beginning One thing to 
// note, though p was required yet it was 
// removed/deleted first from its position 
// and then it is inserted to some other 
// position. Thus, p contributes one to the 
// deletion_count and one to the 
// insertion_count.

// ANS--******
// return m+n- (2*dp[n][m]) only difference
// ****
#include <bits/stdc++.h>
using namespace std;
int noLongestSub(string s1, string s2, int n, int m){ 
    vector<vector<int>>dp(n+1, vector<int>(m+1));
    for(int i=0; i<= n; i++){
        for(int j=0; j<= m; j++){
            if(n==0 || m==0){
                dp[i][j] = 0;
            }
        }
    }
    for(int i=1; i<= n; i++){
        for(int j=1; j<= m; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    
    return m + n -(2*dp[n][m]);
}
int main(){
    string s1, s2;
    cin>>s1>>s2;
    int n = s1.length();
    int m = s2.length();
    cout<<noLongestSub(s1,s2, n, m);
    return 0;
}