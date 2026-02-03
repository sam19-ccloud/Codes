#include<iostream>
using namespace std;

int add(int x,int y){
    return x+y;
} 
int sub(int x,int y){
    return x-y;
}
int mult(int x,int y){
    return x*y;
}
int divi(int x,int y){
    return x/y;
}
void greeting(){
    cout<<"good morniong";
 } 

int main() 

{  cout<<"!!Simple Calculator!!"<<endl;
int x,y;
cout<<"Enter x and y ";
cin>>x>>y;

 
int sum = add(x,y); 
cout<<"sum = " << sum <<endl;
int subt=sub(x,y);
cout<< "sub = " << subt << endl;
int mul=mult(x,y);
cout<< "mul = " << mul << endl;
int div=divi(x,y);
cout<< "div= " << div << endl;
greeting();
}