#include <bits/stdc++.h>
using namespace std;
class God{
    int x;
    public:
    God(int n){
        x = n;
    }
    
    friend void printMe(God &obj2);
};
void printMe(God &obj2){//here printMe is friend function, which can access private data of God class.
   cout<<obj2.x<<endl;
   return;
}
int main(){
    God ram(5);
    // cout<<ram.x;
    printMe(ram);
    return 0;
}