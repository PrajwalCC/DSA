#include <bits/stdc++.h>
using namespace std;
int noLongestSub(string s1, string s2, int n, int m){ 
    if(n==0 || m==0){
        return 0;
    }
    if(s1[n-1] == s2[m-1]){
        return 1 + noLongestSub(s1,s2,n-1,m-1);
    }
    else{
        return max(noLongestSub(s1,s2,n-1,m), noLongestSub(s1,s2, n, m-1));
    }
}
int main(){
    string s1, s2;
    cin>>s1>>s2;
    int n = s1.length();
    int m = s2.length();
    cout<<noLongestSub(s1,s2, n, m);
    return 0;
}