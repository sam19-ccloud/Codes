#include<iostream>
using namespace std;

class Vehicle{
private :
string vehno;
public:
Vehicle():vehno("M10923"){}

    friend int printvehno();

};
 int printNumber(Box b)  
{  
    b.length += 10;  
    return b.length;  
}  
}