#include<iostream>
using namespace std;

class Vehicle{
private:
    string vehno;  // Private member
public:
    int Number;  // Public member
    Vehicle() : vehno("MH14AD999"), Number(1234) {}  // Constructor initializes both vehno and Number

    // Friend function declaration to access private members
    friend int printvehno(Vehicle a);
};

// Friend function definition to access private members
int printvehno(Vehicle a) {
    cout << "Vehicle number is: " << a.vehno << endl;  // Accessing private member 'vehno'
    return a.Number;
}

int main(){
    Vehicle a;
    // Call the friend function to print vehno and return Number
    cout << "Vehicle number is: " << printvehno(a) << endl;   
    return 0;
}
