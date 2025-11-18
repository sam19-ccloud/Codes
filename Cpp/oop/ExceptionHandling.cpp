#include<iostream>
using namespace std;

int main(){

    int num=10;
    int den=0;

    
    // throw(1);
    try{
        if(den==0){
            throw 1;
        }
        cout<<num/den<<endl;
    }catch(int a){
        cout<<"Please dont enter zero as deniminator"<<endl;
    }

    cout<<"end of the code"<<endl;
}
