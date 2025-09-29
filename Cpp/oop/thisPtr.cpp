#include<iostream>
using namespace std;

class Student{
    public:
    int id;
    float marks;
    string name;

    void insert(int id,float marks,string name){
        this->id=id;
        this->marks=marks;
        this->name=name;
    }
    void show(){
        cout<<"ID : "<<id<<endl;
        cout<<"Marks : "<<marks<<endl;
        cout<<"name : "<<name<<endl;
        cout<<this;
    }
};

int main(){
Student s1;

cout<<&s1;
s1.insert(101,90.5,"harry");
s1.show();
}