#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,X;
        cin>>n>>X;
        int A[n],hash[100000]={0};
        int sum,flag=0;
        for(int i=0; i<n; i++){
            cin>>A[i];
            hash[A[i]]=1;
        }
        for(int i=0; i<n; i++){
            sum = X - A[i];
            for(int j=i+1; j<n; j++){
                sum = sum - A[j];
                if(hash[sum]==1 && sum != A[i] && sum != A[j]){
                    cout<<"yes--> "<<A[i]<<" "<<A[j]<<" "<< sum <<endl;
                    flag=1;
                    break;
                }
                sum = X - A[i];
            }
            if(flag==0){
               cout<<"No"<<endl;
            }
        }

    }
    return 0;
}