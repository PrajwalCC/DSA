#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int i=1,j=n-2,mid;
    while(i<=j){
        mid = i + ((j-i)/2);
        if(a[mid]>a[mid+1] && a[mid]>a[mid-1]){
            cout<<"mid--- Index -> "<<mid<<" , element = "<<a[mid]<<endl;
            break;
        }
        else if(a[mid+1] > a[mid]){
            i=mid+1;
        }
        else if(a[mid-1] > a[mid]){
            j=mid-1;
        }
        else{
            i=mid+1;
        }
    }
    cout<<max(max(a[0], a[mid]),a[n-1]);
    return 0;
}