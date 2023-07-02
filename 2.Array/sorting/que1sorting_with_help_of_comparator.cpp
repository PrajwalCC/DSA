// https://practice.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1
// it is like custom sorting
#include <bits/stdc++.h>
using namespace std;
bool custom_comparator(string a, string b){
    return a+b > a+b;
}
int main(){
    int n;
    cin>>n;
    vector<string> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end(),custom_comparator);
    string ans = "";
    for(int i=0; i<n; i++){
        ans += arr[i];
    }
    cout<<ans;
    return 0;
}