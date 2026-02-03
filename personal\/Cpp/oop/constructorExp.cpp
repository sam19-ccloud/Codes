#include<iostream>
using namespace std;

class A{
public:
 static int counter;
    A(){
        counter++;
        cout<<endl<<"A called "<<counter<<endl ;
    }
    
    A(int b){
        cout<<b<<endl;
    }
};
 int A::counter = 0;

int main(){
    A a2;
    A a1 = A(10);
    A a3;
}

