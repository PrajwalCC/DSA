#include <bits/stdc++.h>
using namespace std;
class Complex{
    public:

        int real;
        int img;

        Complex(int x, int y){
            real = x;
            img = y;
        }

        Complex operator*(Complex & n){
            Complex ans(0,0);
            ans.real = real + n.real;
            ans.img = img + n.img;
            return ans;
        }
};
int main(){
    Complex c1(1, 2);
    Complex c2(1,3);
    Complex c3 = c1*c2;
    cout<<c3.real<<" i"<<c3.img;
    return 0;
}