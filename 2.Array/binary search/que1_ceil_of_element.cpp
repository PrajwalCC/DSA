// ceil-> smallest element which is greater than key;
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int key;
    cin>>key;
    int i=0,j=n-1,mid;
    while(i<=j){
        mid=i+((j-i)/2);
        if(a[mid] == key){
            cout<<"key is present at index "<<mid<<endl;
        }
        else if(a[mid] > key){
            j=mid-1;
        }
        else if(a[mid] < key){
            i=mid+1;
        }
    }
    cout<<"i = "<<i<<" , j = "<<j<<endl;
    cout<<"ceil is at index "<<i<<" = "<<a[i];
    return 0;
}