// ques--Function to find length of longest increasing subsequence.
// ***this method is only useful for giving length of LIS .. not for printing LIS 
// becoz v vector is not the subsequence of that array , it is just manipulated ...
// ANSWER---> *****length of LIS = v.size()*****
// Time comp == nlog(n) which is best that n^2 (prev methods)

// this is only for length ,but for printing LIS see 42th video of striver dp series 


#include <bits/stdc++.h>
using namespace std;
int solve(int a[], int n){
    vector<int> v;
    v.push_back(a[0]);
    for(int i=1; i<n ;i++){
        if(v.back() < a[i]){
            v.push_back(a[i]);
        }
        else{
            int idx;
            idx = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
            v[idx] = a[i];
        }
    }
    return v.size();
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cout<<solve(a,n);
    return 0;
}