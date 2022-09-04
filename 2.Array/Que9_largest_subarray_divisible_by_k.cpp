#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k,sum=0;
    cin>>n>>k;
    int arr[n];
    for(int p=0; p<n;p++){
        cin>>arr[p];
        sum=sum+arr[p];
        arr[p]=sum%k;
    }
    
    for(int p=0; p<n;p++){
        cout<<arr[p]<<" ";
    }
    cout<<endl;
    int i=0, j=i+1, max_len=0, len=0;
    while(i<n){
        if(arr[j]==0){
           len=j;
           max_len = max(max_len,len);
           if(j<n-1){
                j++;
            }
            else{
                i++;
                j=i+1;
            }
        }

        if(arr[j]!=arr[i]){
            j++;
        }
        else if(arr[j]==arr[i]){
            len = j - i;
            max_len = max(max_len,len);
            if(j<n-1){
                j++;
            }
            else{
                i++;
                j=i+1;
            }
        }

        if(j>=n){
            i++;
            j=i+1;
        }
    }
    cout<<max_len;
    return 0;
}