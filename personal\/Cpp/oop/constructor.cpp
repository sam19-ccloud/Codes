#include<iostream>
using namespace std;

class Toyota{
    public:
    string Model;
    string Type;

    Toyota(){
        cout<<"Your vechile is listed"<<endl;
    }
    
     void insert (string m,string t){
        Model=m;
        Type=t;
    }
    void display(){
        cout<<"Model: "<<Model<<endl;
        cout<<"Type: "<<Type<<endl;
    }
};
 int main (){
Toyota v1;
v1.insert("Fortuner","SUV");

Toyota v2;
v2.insert("Camry","Sedan");

v1.display();
v2.display();
}