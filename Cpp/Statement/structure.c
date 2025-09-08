#include<stdio.h>
#include<string.h>

    struct Student{
    int id;
    char name[30];
    float marks;
    };
    int main(){
       
            printf("Enter information about student \n");

    struct Student s ;

    printf("Roll no of student \n");
    scanf("%d",&s.id);
    printf("Name of student \n");
    scanf("%s",&s.name);
    printf("Marks  of student \n");
    scanf("%f",&s.marks);
    
    printf("Roll no of student %d \n",s.id);
    printf("Name of student %s \n",s.name);
    printf("Marks  of student %f \n",s.marks);
}