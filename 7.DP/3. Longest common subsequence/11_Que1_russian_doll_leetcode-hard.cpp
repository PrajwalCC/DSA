// https://leetcode.com/problems/russian-doll-envelopes/
// resource = love babbar
// similar --> LIS(DP + Binary search)
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> height, int n){
    vector<int>v;
    v.push_back(height[0]);
    for(int i=1; i<n; i++){
        if(height[i] > v.back()){
            v.push_back(height[i]);
        }
        else{
            int idx;
            idx = lower_bound(v.begin(), v.end(),height[i]) - v.begin();
            v[idx] = height[i];
        }
    }
    return v.size();
}
static bool dynamicSortFunc(vector<int>& v1, vector<int>& v2) {
    if(v1[0] == v2[0])//if width is same,
        return v1[1] > v2[1];//sort in decresing order
    
    return v1[0] < v2[0];//if width is not same, then sort in increasing order
}
int main(){
    int n=4;
    vector<vector<int>>envolops(n+1, vector<int>(2));
    envolops={{5,4},{6,4},{6,7},{2,3}};

    sort(envolops.begin(), envolops.end(), dynamicSortFunc);
    vector<int>height;
    for(int i=0; i<n; i++){
        height.push_back(envolops[i][1]);
    }

    cout<<solve(height,n);
    return 0;
}