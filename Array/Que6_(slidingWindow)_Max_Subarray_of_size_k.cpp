// sliding window technique, fix size window
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    int arr[n];

    for(int p=0; p<n;p++){
        cin>>arr[p];
    }
    
    if(k>n){
        cout<<-1;
        return 0;
    }
    int sum=0;
    for(int i=0; i<k; i++){
        sum = sum + arr[i];
    }
    int max_sum = sum;
    for(int i=k; i<n; i++){
          sum = sum + arr[i];
          sum = sum - arr[i-k];
          max_sum = max(sum,max_sum);
    } 
    cout<<max_sum;
    return 0;
}