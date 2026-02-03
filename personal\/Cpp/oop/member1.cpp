#include <iostream>
using namespace std;

class Number {
public:
    Number(){
        cout<<"Number is added"<<endl;
    }

    void even_odd() {
        int n;
        cout<<"Enter a number: ";
        cin>>n;
        if(n % 2 == 0) {
            cout << n << " is an even number." << endl;
        }else{
            cout<<n<<"is an odd number."<<endl;
        }
    }
};

int main() {
    Number obj; 
    obj.even_odd();    

}
