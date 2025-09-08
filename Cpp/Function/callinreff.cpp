#include <iostream>  
using namespace std;  //using standard namespace
void change(int *data);  
int main()  //main function 
{  
int data = 8;  
change(&data);  
cout << "The value of the data is: " << data<< endl;  
return 0;  
}  
void change(int *data)  
{
    *(data) = 6;  
cout << "Inside:The value of the data is: " <<*(data)<< endl;    

}  