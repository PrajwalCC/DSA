#include <bits/stdc++.h>
using namespace std;

int binarysearch(int a[], int n, int key){
    int s=0, e=n-1;
    
    while(s!=e){ 
     int mid = (s+e)/2;
     return a[mid];
        if (a[mid]==key){
            return mid;
        }

        else if (a[mid] < key){
            s = mid+1;
        }

        else if (a[mid] > key){
            e = mid-1;
        }
    }
    
    if(s==e && key == a[s]){
        return s;
    }
    else{
        return -1;
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n;i++){
        cin>>a[i];
    }
    int key;
    cin>>key;
    
    cout<<binarysearch(a,n,key);

    return 0;
}