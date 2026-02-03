#include<stdio.h>

int main(){

    int arr[5] = {1,2,3,4};


    printf("Oroginal Array : \n");
    int i=0;
    for(i=0;i<5;i++){
        printf("%d\t",arr[i]);
    }


    int val,pos;

    printf("Enter value : ");
    scanf("%d",&val);
    printf("Enter Position : ");
    scanf("%d",&pos);


    for(i=4;i>=pos;i--){
        arr[i] = arr[i-1];
    }

    arr[pos] = val;

      printf("\nUpdated Array : \n");
     i=0;


    for(i=0;i<5;i++){
        printf("%d\t",arr[i]);
    }

 for (i = pos; i < 4; i++) {
        arr[i] = arr[i + 1];
    }
    // arr[4] = 0;
      printf("\nUpdated Array  : \n");
     i=0;
 
     
    for(i=0;i<5;i++){
        printf("%d\t",arr[i]);
    }





}


