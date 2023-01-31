#include <bits/stdc++.h>
using namespace std;
bool check(string s1, string s2){
    int n = s1.size();
    int m = s2.size();
    int i=0,j=0;
    while(i < n){
        if(s1[i] == s2[j]){
            i++;
            j++;
            if(j == m){
                return true;
            }
        }
        else{
            i = i-j+1;//catch
            j=0;
        }
    }
    return false;
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<check(s1,s2);
    return 0;
}