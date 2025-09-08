#include<stdio.h>

int main(){
    int a = 10;
    int *p = &a;
    int **dp = &p;

     printf("A's Value=%d\n",a);
     printf("A's Address=%d\n",&a);

     printf("p's value = %d\n",p);
     printf("p's address = %d\n",&p);
     printf("A's value using Ptr = %d\n",*p);

    printf("dp's value = %d\n",dp);
     printf("dp's address = %d\n",&dp);
     printf("P's value using Ptr = %d\n",*dp);
     printf("A's value using Ptr = %d\n",**dp);
}