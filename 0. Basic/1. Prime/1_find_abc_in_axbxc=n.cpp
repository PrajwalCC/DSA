// find a,b,c 
// given, axbxc = n
// where a,b,c is not equal to 1
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n= 54;
    int a,b,c;
    for(int i=2; i*i <= n; i++){
        if(n%i == 0){
            a=i;
            break;
        }
    }
    n=n/a;
    for(int i=2; i*i <=n; i++){
        if(n%i == 0){
            if(i != a){
                b=i;
            }
            if((n/i) != a){
                b=min(b,(n/i));
            }
        }
    }
    c=n/b;
    if(a!=b && b!= c && c!= 1){
        cout<<a<<" "<<b<<" "<<c; 
    }else{
        cout<<"No such values are possible";
    }
    return 0;
}