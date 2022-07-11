#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[5];
    for(int i=0; i<5;i++){
        cin>>a[i];
    }
    int key;
    cin>>key;

    for(int i=0; i<5; i++){
       if(a[i]==key){
           cout<< i;
           break;
       }
       else if(i==4 && a[4]!=key){
           cout<<"-1";
       }
    }
    return 0;
}