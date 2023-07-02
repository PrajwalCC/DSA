#include <bits/stdc++.h>
using namespace std;
int countNoOfStudent(int a[], int n, int maxAllocated){
    int oneSum = 0, count=1, i=0;
    while(i < n){
        if(oneSum+a[i] <= maxAllocated){
            oneSum += a[i];
        }
        else{
            oneSum=a[i];
            count++;
        }
        i++;
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    int maxPages=0, sumPages=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        maxPages=max(maxPages,a[i]);
        sumPages+=a[i];
    }
    int m;
    cin>>m;
    int i=maxPages, j=sumPages, mid;
    while(i<=j){
        mid = i+((j-i)/2);
        int count = countNoOfStudent(a,n,mid);
        if(count > m){
            i=mid+1;
        }
        else if(count < m){
            j = mid-1;
        }
        else if(count == m){
            j = mid-1;
        }
    }
    cout<<"ans is = "<<i;
    return 0;
}