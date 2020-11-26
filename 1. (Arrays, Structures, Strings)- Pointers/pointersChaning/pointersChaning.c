#include<stdio.h>

void main(){
    int x,*p1,**p2,*p3,**p4;
    printf("Enter the value of x: \n");
    scanf("%d",&x);
    p1=&x;
    p2=&p1;
    p3=p1;
    p4=p2;
    printf("&x  %u \n",&x);
    printf("p1  %u \n",p1);
    printf("&p1  %u \n",&p1);
    printf("p2  %u \n",p2);
    printf("&p2  %u \n",&p2);
    printf("p3  %u \n",p3);
    printf("p4  %u \n",p4);

    printf("*p1  %d \n",*p1);
    printf("**p2  %d \n",**p2);
    printf("*p3  %d \n",*p3);
    printf("**p4  %d \n",**p4);
}