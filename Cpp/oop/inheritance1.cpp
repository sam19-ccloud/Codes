#include<iostream>
using namespace std;
class Base{
public:  
    int x;  
};  
  
class Derived:public Base{  
public:  
    int y;  
};  
  
int main()  
{ Derived Tpoint;    
    Tpoint.y = 10;  
    Tpoint.x = 15;  
    cout<<"Derived Class Value: "<<Tpoint.y<<endl;  
    cout<<"Base Class Value: "<<Tpoint.x<<endl;  
  
    return 0;  
}  