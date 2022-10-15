//got this in linkedin feed,Bhavika bhatia
// not understood the logic behind this 
#include <bits/stdc++.h>
using namespace std;

int main(){
    int x=5, y=14;
    int data ;
    while(y!=0){
        data=x&y;
        x= x ^ y;
        y = data << 1;
    }
    cout<<x;
    return 0;
}