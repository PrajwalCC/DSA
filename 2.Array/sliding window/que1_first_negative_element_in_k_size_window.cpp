// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cin>>k;
    vector<int> neg;
    for(int i=0; i<k; i++){
        if(a[i] < 0){
            neg.push_back(a[i]);
        }
    }
    int i=0,j=k-1;
    vector<int> ans;
    while(j < n){
        if(neg.size() == 0){
            ans.push_back(0);
            i++;
            j++;
            if(j<n && a[j]<0){
                neg.push_back(a[j]);
            }
            continue;
        }
        else{
            ans.push_back(neg[0]);
        }
        if(a[i] == neg[0]){
            neg.erase(neg.begin());
        }
        i++;
        j++;
        if(j<n && a[j]<0){
            neg.push_back(a[j]);
        }
    }
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}