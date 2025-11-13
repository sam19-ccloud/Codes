#include<iostream>
using  namespace std;

class tyre{
    public:
    static int count;
    tyre(){
        cout<<"  TYRE added successfully..."<<endl;
        count++;
    }
    void type(int a){
        cout<<"type of tyre to veh :"<<a<<endl;
    }
      void type(int a,int b){
        cout<<"type of tyre to veh :"<<a<<","<<b<<endl;
    }
      void type(int a,int b,int c){
        cout<<"type of tyre to veh :"<<a<<","<<b<<","<<c<<endl;
    }
    
};
 
int main(){
    tyre a;
    a.type(1);
     
    a.type(1,2);
    cout<<"Number of tyre: "<<<<endl;
    a.type(1,2,3);
    
   
     
}


