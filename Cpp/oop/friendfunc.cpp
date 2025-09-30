#include<iostream>
using namespace std;

class Vehicle{
  private:
        string vehno;
  public:
        int Number;
        Vehicle():vehno("MH14AD999"){}
        friend int printvehno(Vehicle);
};
  int printNumber(Vehicle a){   
    return a.Number;  
};
int main(){
    Vehicle a;
    cout<<"Vehicle number is: "<<printNumber(a)<<endl;    
      
}


