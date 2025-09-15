#include <iostream>  
using namespace std;  
class Student {  
private:  
    string name;  
    int age;  
public:  
    Student(string n, int a) : name(n), age(a) {}  
    void display() const {  
        cout << "Name: " << name << ", Age: " << age << endl;  
    }  
};  
  
int main() {  
    Student studname("John", 24);  
    studname.display();  
  
}  
