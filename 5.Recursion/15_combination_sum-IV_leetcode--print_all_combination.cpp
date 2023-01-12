#include <bits/stdc++.h>
using namespace std;
void print(vector<int>ans){
    int n = ans.size();
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
void printAll(vector<vector<int>> final){
    int n = final.size();
    for(int i=0; i<n; i++){
        print(final[i]);
    }
    cout<<endl;
}
void solve(vector<int> num, int n, int target, vector<vector<int>>& final, vector<int>& ans){
    if(target == 0){
        final.push_back(ans);
    }

    if(target < 0){
        // ans.pop_back();
        return;
    }

    for(int i=0; i<n; i++){
        ans.push_back(num[i]);
        solve(num,n,target-num[i],final,ans);
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
    vector<int> ans;
    vector<vector<int>> final;
    solve(num,n,target,final,ans);
    cout<<"Printing all the possible combinations"<<endl;
    printAll(final);
    return 0;
}