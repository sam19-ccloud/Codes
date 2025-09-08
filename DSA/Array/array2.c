#include<stdio.h>
int main(){
    int marks[3];
    int i;
    printf("Enter marks: ");
    
    for(i=0;i<4;i++){
        scanf("%d",&marks[i]);
    }

    for(i=0;i<4;i++){
    
    printf("%d \n ",marks[i]);
    }
}