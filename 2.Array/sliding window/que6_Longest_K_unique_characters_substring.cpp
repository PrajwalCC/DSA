#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int k;
    cin>>s>>k;
    map<int,int> m;
    int n = s.size();
    int maxLen = -1;
    map<char,int> uniq;
    int i=0, j=0;
    uniq[s[j]]++;
    while(j < n){
        int check = uniq.size();
        if(check == k){
            maxLen = max(maxLen, j-i+1);
        }
        if(check > k){
            while(check > k){
                uniq[s[i]]--;
                if(uniq[s[i]]==0){
                    uniq.erase(s[i]);
                }
                check = uniq.size();
                i++;
            }
            if(check == k){
                maxLen = max(maxLen, j-i+1);
            }
        }
        // aabaca
        j++;
        if(j < n){
            uniq[s[j]]++;
        }
    }
    cout<<maxLen;
    return 0;
}