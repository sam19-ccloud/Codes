#include<iostream>
using namespace std;


class Inc{
    int val;

    public:
    Inc(int a):val(a){}

    Inc operator++(){
      val+=2;
      return val;
    }


    void display(){
        cout<<"Value is "<<val;
    }

};


int main(){
    Inc i = Inc(10);
    ++i;
    ++i;
    i.display();

}