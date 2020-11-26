#include<stdio.h>

char *removeChar(char [],char );

void main(){
    char a[10],element[1];
    printf("Enter the string:\n");
    scanf("%s",a);
    printf("Enter the character to be removed from the string %s:\n",a);
    scanf("%s",element);
    printf("The string after removing all the occurences of %s is: %s\n",element, removeChar(a,element));
}

char *removeChar(char a[],char element){
    char *ptr=a;

    printf("%s\n",a);

    return *a;
}
