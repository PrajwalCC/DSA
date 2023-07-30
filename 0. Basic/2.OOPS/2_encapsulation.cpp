#include <bits/stdc++.h>
using namespace std;
class abc{
int x;
public:
 void set(int n){
   x = n;
 }
 int get(){
    return x;
 }
};
int main(){
    abc obj;
    obj.set(4);
    cout<<obj.get();
    return 0;
}