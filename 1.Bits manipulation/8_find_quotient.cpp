#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    int count =0,i=1;

    for(int j=30; j>=0; j--){
        if(b >= (1<<j)){
            count = j+1;
            break;
        }
    }
    cout<<"no. of bits in divisor"<<count<<endl;
    count=count-1;
    cout<<"dividend = "<<(a>>count)<<endl;
    // while(b>=i){
    //     count++;
    //     i = i*2;
    // }
    // cout<<(a>>2);
    return 0;
}