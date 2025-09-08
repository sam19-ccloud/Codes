#include<stdio.h>
struct Employee{
    int id;
    char name[30];
    float salary;
};
int main(){
    struct Employee E1={101,"Raj",12000.0000};
    printf("ID :%d\n",E1.id);
    printf("Name :%s\n",E1.name);
    printf("Salary :%f\n",E1.salary);


}