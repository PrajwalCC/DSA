#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n, x;
        cin >> n >> x;
        int arr[n];
        int hash[1000] = {0};
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            hash[arr[i]] = 1;
        }
        int sum;
        for (int i = 0; i < n; i++)
        {
            
            if( hash[x-arr[i]] == 1 && arr[i] != x-arr[i]){
                cout<<"Yes ->"<<arr[i] <<" "<< (x-arr[i])<<endl;
                break;
            }
            if(i=n-1){
                cout<<"No"<<endl;
            }
        }
    }
    return 0;
}