#include<iostream>
using namespace std;

class A{
    public:
    // inside member function 
    void sayHi(){
        cout<<"HI"<<endl;
    }

    // outside member function 

    void sayHello();
};

void A::sayHello(){
    cout<<"Hello";
}

int main(){
A a1;
a1.sayHello();
a1.sayHi();
}