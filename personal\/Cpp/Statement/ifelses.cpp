#include<iostream>
using namespace std;

int main(){
    int age;

    cout<<"Enter your Age  ";
    cin>>age;

    if(age>80){
        cout<<"You cant vote";
    }
    else if (age>=18){
        cout<<"you can vote";
    }
    else{
        cout<<"You are not elligible";
    }

}