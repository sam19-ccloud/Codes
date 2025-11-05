#include <iostream>  
using namespace std;  //using standard namespace  
class Appliance {  //Base class  
public:  
    void powerStatus() {  
        cout << "Appliance is turned on." << endl;  
    }  
};  
class WashingMachine : public Appliance {   //derived class1   
public:  
    void washClothes() {  
        cout << "Washing clothes..." << endl;  
    }  
};  
class SmartWashingMachine : public WashingMachine {   //derived_class2  
public:  
    void wifiControl() {  
        cout << "Smart control via WiFi enabled." << endl;  
    }  
};  
int main() {  //Main Function  
    SmartWashingMachine sm;  
    sm.powerStatus();     
    sm.washClothes();     
    sm.wifiControl();     
    return 0;  
}  