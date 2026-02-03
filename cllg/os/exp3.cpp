#include <iostream> 

#include <unistd.h> 

using namespace std; 

int main(){ 

 int pid=fork(); 

 if(pid==0) 

 cout<<"Child Process Running"<<endl; 

 else 

 cout<<"Parent Process Running"<<endl; 

 return 0; 
 }
