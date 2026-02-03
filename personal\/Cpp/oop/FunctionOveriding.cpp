#include<iostream>

using namespace std;

class A{
    public:
    void sayHi(){
        cout<<"A Hi"<<endl;
    }
};

class B: public A{
    public:
       void sayHi(){

        cout<<"B Hi"<<endl;
    }
    void SayHello(){
        cout<<"Hello"<<endl;
    }
};

int main(){
    B b1;
    b1.sayHi();
}