#include <bits/stdc++.h>
using namespace std;
class Parent{
    public:
    int x;

    virtual void print(){
        cout<<"This is parent class"<<endl;
    }
    void show(){
        cout<<"This is parent class"<<endl;
    }
    void set(){
        x = 1;
    }
};

class Child: public Parent{
    public:
    int x;
    void print(){
        cout<<"This is Child class"<<endl;
    }
    void show(){
        cout<<"This is Child class"<<endl;
    }
    void set(){
        x=2;
    }
};

int main(){
    Parent *p;
    Child c;
    p = &c;
    p->print();
    p->show();
    p->set();
    cout<<p->x<<endl;
    c.set();
    cout<<c.x<<endl;
    return 0;
}