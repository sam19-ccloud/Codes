#include<iostream>
using namespace std;

class Student {
    // field / data member / 
    public:
    int id;
    string name;
// Default Constructor
    Student(){
        cout<<"Student added"<<endl;
    }
// Parameterized Constructor

    Student(int i,string n){
         id=i;
        name=n;
    }
    // functionalities / member functions/ inside member function
    void insert(int i,string n) {
        id=i;
        name=n;
    }
    void show(){
        cout<<"ID :"<<id<<endl;
        cout<<"Name :"<<name<<endl;
    }
};

int main(){
// class obj
Student s1;
// s1.insert(101,"jhon");
Student s2;
Student s3;
s2.insert(102,"jane");

s1.show();
s2.show();

// Student s1 = Student(101,"jhon");
// s1.insert(101,"jhon");
// Student s2 = Student(102,"Jane");
// s2.insert(102,"jane");





}
