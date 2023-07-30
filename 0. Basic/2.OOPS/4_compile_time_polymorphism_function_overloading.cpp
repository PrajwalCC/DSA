// functions gets selected at compile time. 
#include <bits/stdc++.h>
using namespace std;
class totalSum{
    public:
    int add(int x){
        return x;
    }
    int add(int x,int y){
        return x+y;
    }
    float add(float x,float y){
        return x+y;
    }
    int add(int x,int y, int z){
        return x+y+z;
    }
};
int main(){
    totalSum account;
    cout<<account.add(5)<<endl;
    cout<<account.add(5,5)<<endl;
    cout<<account.add(float(5.3),float(5.2))<<endl;
    cout<<account.add(5,5,5)<<endl;
    return 0;
}