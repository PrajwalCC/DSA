// https://leetcode.com/problems/combination-sum-ii/description/
// resource -- striver
#include <bits/stdc++.h>
using namespace std;
void print(vector<int>ans){
    int n = ans.size();
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
void solve(vector<int>num,int target,int idx,vector<int>& ans,vector<vector<int>>& final){
    
    if(target == 0){
        // print(ans);
        final.push_back(ans);
        return;
    }

    for(int i=idx; i< num.size(); i++){
        if(i>idx && num[i]==num[i-1]){
            continue;
        }
        if(num[i] > target){
            break;
        }
        ans.push_back(num[i]);
        solve(num,target-num[i],i+1,ans,final);
        ans.pop_back();
    }
    return;
}
int main(){
    int n;
    cin>>n;
    vector<int>num;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        num.push_back(temp);
    }
    int target;
    cin>>target;
    sort(num.begin(), num.end());
    vector<int> ans;
    vector<vector<int>> final;
    solve(num,target,0,ans, final);
    cout<<"Total no possible sets = "<<final.size();
    return 0;
}