#include<iostream>
using namespace std;

int main(){
    int a = 10;
    int *p = &a;
    int **dp = &p;

     cout<<"A's Value= "<<a <<endl;
     cout<<"A's Address= "<<&a<<endl;

     cout<<"p's value = "<<p<<endl;
     cout<<"p's address = "<<&p <<endl;
     cout<<"A's value using Ptr = "<<*p<<endl;

     cout<<"dp's value = "<<dp<<endl;
     cout<<"dp's address = "<<&dp<<endl;
     cout<<"P's value using Ptr = "<<*dp<<endl;
     cout<<"A's value using Ptr =  "<<**dp;
}
