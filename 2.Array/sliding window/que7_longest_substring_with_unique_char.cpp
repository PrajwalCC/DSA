#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    map<int,int> m;
    int n = s.size();
    int maxLen = -1;
    map<char,int> uniq;
    int i=0, j=0;
    while(j < n){
       if(m.find(s[j]) == m.end()){
         maxLen = max(maxLen, j-i+1);
         m[s[j]]++;
         j++;
       }
       else{
         while(m.find(s[j]) != m.end()){
            m[s[i]]--;
            if(m[s[i]] == 0){
                m.erase(s[i]);
            }
            i++;
         }
         maxLen = max(maxLen, j-i+1);
       }
    }
    cout<<maxLen;
    return 0;
}