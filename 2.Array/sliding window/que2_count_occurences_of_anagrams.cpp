// https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1
#include <bits/stdc++.h>
using namespace std;

int main(){
    string txt,pat;
    cin>>txt>>pat;
    unordered_map<char,int>mp1;
    unordered_map<char,int>mp2;
    int n = txt.size();
    int k = pat.size();
    int i=0,j=0;
    while(j < k){
        mp2[pat[j]]++;
        j++;
    }
    j=0;
    while(j < k){
        mp1[txt[j]]++;
        j++;
    }
    int count=0;
    if(mp1 == mp2){
        count++;
    }
    while(j < n){
        if(mp1[txt[i]] == 1){
            mp1.erase(txt[i]);
        }
        else{
            mp1[txt[i]]--;
        }
        mp1[txt[j]]++;
        i++;
        j++;
        if(mp1 == mp2){
            count++;
        }
    }
    cout<<count;
    return 0;
}