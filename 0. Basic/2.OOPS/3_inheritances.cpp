#include <bits/stdc++.h>
using namespace std;
class parent1{
 public:
 parent1(){
    cout<<"This is parent1 class"<<endl;
 }
};

class parent2{
 public:
 parent2(){
    cout<<"This is parent2 class"<<endl;
 }
};

class child: public parent1, public parent2{//multiple inheritance
    public:
    child(){
        cout<<"This is child class"<<endl;
    }
};

class child1: public parent1{//single level inheritance
    public:
    child1(){
        cout<<"This is child class"<<endl;
    }
};

class grandChild: public child{//multi level inheritance
    public:
    grandChild(){
        cout<<"This is child class"<<endl;
    }
};

int main(){
    child prajwal;
    return 0;
}