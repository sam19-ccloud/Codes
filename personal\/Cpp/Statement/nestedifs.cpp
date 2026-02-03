#include <iostream>  
using namespace std;  
int main() {  
    int age; 
   
    cout << "Enter your age: ";  
    cin >> age;  
    

    if (age >= 18) {  
         cout << "You need an ID to enter." << endl;  
        }  
    else {  
        cout << "You are not old enough to enter." << endl;  
    }  
    return 0;  
}  