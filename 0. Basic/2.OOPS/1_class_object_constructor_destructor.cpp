// Fruits is a class
// apple,mango,banana are objects

#include <bits/stdc++.h>
using namespace std;
class fruits{
    public:// public section can be access from outside of class
    string name;
    string colour;

    fruits(){ //default constructor, use to intialize the object
        name = "Pineapple";
        colour = "Green";
    }

    fruits(string s1, string s2){ // parameterised constructor - initialise object by passing arguments
        name = s1;
        colour = s2;
    }

    fruits( fruits & f){// copy constructor - initialise object by other object
        name = f.name;
        colour = f.colour;
    }

    ~fruits(){ //Destructor 
        cout<<"Fruit object is been deleted"<<endl;
    }
};
int main(){
    fruits apple;// creating object 
    apple.name = "Apple";
    apple.colour = "red";
    cout<<apple.name<<" - "<<apple.colour<<endl;

    fruits *mango = new fruits();//creating object with help of pointer
    mango -> name = "Mango";
    mango -> colour = "Yellow";
    cout<<mango->name<<" - "<<mango->colour<<endl;
    delete mango;

    fruits favFruit;//default
    cout<<favFruit.name<<" - "<<favFruit.colour<<endl;

    fruits banana("Banana", "Yellow");//passing arguments
    cout<<banana.name<<" - "<<banana.colour<<endl;

    fruits otherBanana = banana;// copying from another object
    cout<<otherBanana.name<<" - "<<otherBanana.colour<<endl;
    return 0;
}