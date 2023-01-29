// https://leetcode.com/problems/maximum-height-by-stacking-cuboids/description/
// resource -- love babbar , dp series - video no. 19
#include <bits/stdc++.h>
using namespace std;
bool check(vector<int>base, vector<int>newBox){
    if(newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2]){
        return true;
    }
    else{
        return false;
    }
}
int LIS(vector<vector<int>>cuboids, int n){
    vector<int>curr(n+1);
    vector<int>next(n+1);
    for(int i=n-1; i>=0; i--){
        for(int j = i-1; j>= -1; j--){
            if(j == -1 || check(cuboids[i], cuboids[j])){
                curr[j+1] = max(next[j+1], cuboids[i][2]  + next[i+1]);
            }
            else{
                curr[j+1]  = next[j+1] ;
            }
        }
        next=curr;
    }
    return next[-1+1];
}
int main(){
    int n;
    n=3;
    vector<vector<int>>cuboids(n, vector<int>(3));
    cuboids={{50,45,20}, {95,37,53}, {45,23,12}};
    // sorting dimensions of each cuboid
    for(int i=0; i<n; i++){
        sort(cuboids[i].begin(), cuboids[i].end());
    }
    // sorting whole 2D vector on basis of first dimension of each cuboid vector
    sort(cuboids.begin(), cuboids.end());

    // use LIS
    cout<<LIS(cuboids,n);
    return 0;
}