#include<iostream>
using namespace std;

class Vehicle{
    public:
    int vehno;
    string vehname;
    static string brand ;
    static int count;
    
    Vehicle(){
        cout<<"Vehicle added successfully..."<<endl;
        count++;
    }
    void insert(int id,string Name){
        vehno=id;
        vehname=Name;
    }
    void display(){
        
        cout<<"Vehname: "<<vehname<<endl;
        cout<<"Vehno: "<<vehno<<endl;
    }
};
string Vehicle::brand = "Toyota"; 
int Vehicle::count = 0;

int main(){

Vehicle v1;
v1.insert(1231,"Fortuner");

Vehicle v2;
v2.insert(1232,"Camry");

v1.display();
v2.display();

cout<<"Number of Vehicle registered: "<<Vehicle::count<<endl;
}
