#include<stdio.h>

void createArray(int *p,int size){
    p = (int*) malloc(sizeof(int)*size);
    printf("Array of size %d is Created...",size);

}

void displayArray(int *p,int size){
    int i=0;
    printf("Displaying the elements of an Array :\n");
    for(i=0;i<size;i++){
        printf("%d\t",*(p+i));
    }
}

int main(){
    int *p;
     int size=0;
while(1){
    printf("Enter Operation from following :\n1)Create an Array\n2)Display an Array\n3)Insert in an Array\n4) Delete from an Array\n5)Search in Array\n6)Exit\nEnter Your Choice : ");
    int ch;
    scanf("%d",&ch);



    switch(ch){
        case 1:
        printf("Enter the size of an Array : ");
        scanf("%d",&size);
        createArray(p,size);
        break;
        case 2:
        displayArray(p,size);
        break;
        case 6:
        
        break;

        default:
        printf("Invalid Choice");
        
    }
}
}

