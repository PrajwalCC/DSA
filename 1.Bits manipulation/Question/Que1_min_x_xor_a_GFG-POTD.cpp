#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    int i=0, countB=0;
    while((1<<i) <= b){
        if(b & (1<<i)){
            countB++;
        }
        i++;
    }
    i=0;
    int countA=0;
    string s="";
    while((1<<i) <= a){
        if(a & (1<<i)){
            s.push_back('1');
            countA++;
        }
        else{
            s.push_back('0');
        }
        i++;
    }
    reverse(s.begin(), s.end());
    string ans="";
    if(countA >= countB){
        for(int i =0 ; i<s.length(); i++){
            if((countB > 0) && s[i]=='1'){
                ans.push_back('1');
                countB--;
            }
            else{
                ans.push_back('0');
            }
        }
    }
    else if(countB>countA && a>b ){
        int one = countB - countA;
        ans=s;
        for(int i =ans.length()-1 ; i>=0; i--){
            if(one == 0){
                break;
            }
            if(ans[i]=='0'){
                ans[i]='1';
                one--;
            }
        }
        while(one--){
            ans="1"+ans;
        }
    }
    else if(countB>countA && a<b ){
        int one = countB - countA;
        ans=s;
        for(int i =ans.length()-1 ; i>=0; i--){
            if(one == 0){
                break;
            }
            if(ans[i]=='0'){
                ans[i]='1';
                one--;
            }
        }
        
        while(one--){
            ans="1"+ans;
        }
        
    }
    int n = ans.length();
    int j = 0, v=0 ;
    for(int i=n-1; i>=0; i--){
        if(ans[i] == '1'){
           v += 1<<j;
        }
        j++;
    }
    cout<<v<<endl;
    return 0;
}