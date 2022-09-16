#include <bits/stdc++.h>
using namespace std;
void print(vector<string> v){
    int n=v.size();
    for(int i=0; i<n; i++){
        int length = v[i].length();
        for(int j=0; j<length; j++){
            cout<<v[i][j];
        }
        cout<<endl;
    }
}
string ok(vector<char> v){
    string s="";
    int n=v.size();
    for(int i=0; i<n; i++){
        s=s+v[i];
    }
    return s;
}
int main(){
    string s = "abc";
    int n = s.length();
    map<vector<char>,int> m;
    for(int i=0; i< (1<<n); i++){
        vector<char> ans;
        ans.push_back(s[0]);
        char sub = ' ';
        for(int j=1; j<n; j++){
            if(i & (1<<j)){
                ans.push_back(sub);
            }
            ans.push_back(s[j]);
        }
        m[ans];
    }
    vector<string> final;
    for(auto i:m){
        string temp = ok(i.first);
        final.push_back(temp);
    }
    print(final);
    return 0;
}