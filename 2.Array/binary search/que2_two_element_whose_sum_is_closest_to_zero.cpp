#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int i=0,j=n-1,mid;
    int minSum,sum,left,right;
    minSum = INT_MAX;
    while(i<j){
       sum=a[i]+a[j];
       if(abs(sum) < abs(minSum)){
         minSum = sum;
         left=i;
         right=j;
       }
       if(sum < 0){
         i++;
       }
       else{
         j--;
       }
    }
    cout<<a[left]<<" "<<a[right]<<" "<<minSum<<endl;
    return 0;
}