// https://leetcode.com/problems/reducing-dishes/
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> s, int index, int time){
    if(index == s.size()){
        return 0;
    }
    int included = s[index]*(time+1) + solve(s,index+1, time+1);
    int excluded = solve(s,index+1, time);

    return max(included, excluded);
}
int main(){
    int n;
    cin>>n;
    vector<int>s(n);
    for(int i=0; i<n; i++){
        cin>>s[i];
    }
    
    cout<<solve(s,0,0);
    return 0;
}
