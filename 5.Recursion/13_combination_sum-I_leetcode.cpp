// https://leetcode.com/problems/combination-sum/description/
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
void solve(vector<int>num,int target,int i,vector<int>& ans,vector<vector<int>>& final){
    int n = num.size();
    if(i == n ){
        if(target == 0){
            // print(ans);
            final.push_back(ans);
        }
        return;
    }

    // pick,notPick;
    if(num[i] <= target){
        ans.push_back(num[i]);
        solve(num,target-num[i],i,ans, final);
        ans.pop_back();
    }
    solve(num,target,i+1,ans, final);
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
    vector<int> ans;
    vector<vector<int>> final;
    solve(num,target,0,ans, final);
    cout<<"Total no possible sets = "<<final.size();
    return 0;
}