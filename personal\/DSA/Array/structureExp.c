#include<stdio.h>
#include<string.h>

struct Student{
    int roll_no;
    char name[30];
    float marks;
};

int main(){
    struct Student s1;
    struct Student s2;
    s1.roll_no =101;   
    s2.roll_no =102;   
    strcpy(s1.name,"Alok");
    strcpy(s2.name,"Smarthya");
    s1.marks = 90.9;
    s2.marks = 99.9;

    printf("Roll Number : %d\n",s1.roll_no);
    printf("Name : %s\n",s1.name);
    printf("Marks: %f\n",s1.marks);

    printf("Roll Number : %d\n",s2.roll_no);
    printf("Name : %s\n",s2.name);
    printf("Marks: %f\n",s2.marks);


    struct Student s3 = {103,"Sham",75.5};
    printf("Roll Number : %d\n",s3.roll_no);
    printf("Name : %s\n",s3.name);
    printf("Marks: %f\n",s3.marks);
}