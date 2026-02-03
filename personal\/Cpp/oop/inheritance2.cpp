#include <iostream>  
using namespace std;  
class Appliance { 
public:  
    void powerStatus() {  
        cout << "Appliance is turned on." << endl;  
    }  
};  
class WashingMachine : public Appliance {      
public:  
    void washClothes() {  
        cout << "Washing clothes..." << endl;  
    }  
};  
class SmartWashingMachine : public WashingMachine {    
public:  
    void wifiControl() {  
        cout << "Smart control via WiFi enabled." << endl;  
    }  
};  
int main() {    
    SmartWashingMachine sm;  
    sm.powerStatus();     
    sm.washClothes();     
    sm.wifiControl();     
    return 0;  
}  