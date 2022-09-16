#include <bits/stdc++.h>
using namespace std;
int power(int x, int y){
    if(y==1){
        return x;
    }
    if(y==0){
        return 1;
    }
    long ans=1;
    if(y%2==0){
      ans=power(x,y/2);
      ans*=ans;
    }else{
      ans=power(x,y-1);
      ans*=x;
    }
    return ans;
    
}
int main(){
    cout<<power(2,6);
    
    return 0;
}