#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> num,int n, int target){
    if(target == 0){
        return 1;
    }
    if(target < 0){
        return 0;
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        ans+= solve(num,n,target-num[i]);
    }
    return ans;
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
    cout<<"Total no. of all the possible combinations = ";
    cout<<solve(num,n,target);
    return 0;
}