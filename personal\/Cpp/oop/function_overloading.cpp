#include<iostream>
using  namespace std;

class tyre{
    public: 
 
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
    a.type(1,2,3);
    
   
     
}


