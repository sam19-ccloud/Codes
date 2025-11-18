#include<iostream>

using namespace std;

template <typename T>
class A{
    public:
    T val;

    void insert(T v){
        val =v;
    }

    void show(){
        cout<<"Value : "<<val<<endl;
    }

};


int main(){
    A <int>a1;
    A <float>a2;
    a1.insert(10);
    a2.insert(10.5);
    a1.show();
    a2.show();
}