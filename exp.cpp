#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n - 1] , f[n - 1], sum=0;
        int b[n-1]; 
        for(int i=1; i<= n-1; i++){
            cin>>a[i];
            f[i] = a[i];
            sum=sum+a[i];
        }
        int i = 2, j=1;
        b[j]=a[1];
        while(i<= n-1){
            if(b[j]<=a[i] && (i-j)>1){
                cout<<"i ="<<i<<" "<< a[i]<<endl;
                cout<<"j ="<<j<<" "<< a[j]<<endl;
                a[i] = a[i] - b[j];
                if(a[i]>1){
                    j++;
                    b[j]=a[j];
                }
                cout<<"i ="<<i<<" "<< a[i]<<endl;
                cout<<"j ="<<j<<" "<< a[j]<<endl;
            }
            else if(b[j]<= a[i] && (i - j)<=1){
                cout<<"i ="<<i<<" "<< a[i]<<endl;
                cout<<"j ="<<j<<" "<< a[j]<<endl;
                if(i== n-1){
                    cout<<"enter"<<endl;
                    cout<<"diff"<<a[i] - b[j]<<endl;
                    b[j] = a[i] - b[j];
                    cout<<"b "<<j<<" "<<b[j]<<endl;
                    i++;
                    sum = sum - b[j];
                }else{
                    j++;
                    b[j]=a[n-1];
                    i++;
                }
                cout<<"last i ="<<i<<" "<< a[i]<<endl;
                cout<<"last j ="<<j<<" "<< b[j]<<endl;
            }
            else if(b[j] > a[i]){
                if(i==j){
                    cout<<"i ="<<i<<" "<< a[i]<<endl;
                    cout<<"j ="<<j<<" "<< a[j]<<endl;
                    b[j]=b[j]+a[i];
                    i++;
                    cout<<"i ="<<i<<" "<< a[i]<<endl;
                    cout<<"j ="<<j<<" "<< a[j]<<endl;
                }else{
                    cout<<"i ="<<i<<" "<< a[i]<<endl;
                    cout<<"j ="<<j<<" "<< a[j]<<endl;
                    b[j] = b[j] - a[i] ;
                    i++;
                    cout<<"i ="<<i<<" "<< a[i]<<endl;
                    cout<<"j ="<<j<<" "<< a[j]<<endl;
                }
            }
        }
        
        sum=sum + b[j];
        for(int p=j+1; p<=n-1; p++){
            sum = sum + f[p];
        }
        cout<<sum<<endl;

    }
    return 0;
}