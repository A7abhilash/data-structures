#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct STACK{
    int top;
    char arr[20];
};

typedef struct STACK* stack;

int isEmpty(stack S){
    if(S->top==-1) return 1;
    return 0;
}

int isFull(stack S){
    if(S->top==19) return 1;
    return 0;
}

void push(char c,stack S){
    if(isFull(S)) printf("Stack overflow\n");
    else S->arr[++S->top]=c;
}

char pop(stack S){
    if(isEmpty(S)) printf("Stack underflow\n");
    else return S->arr[S->top--];
}

void reverseString(char string[]){
    stack S = (stack)malloc(sizeof(struct STACK));
    S->top=-1;
    int i,len=strlen(string);

    for(i=0;i<len;i++){
        push(string[i],S);
    }

    for(i=0;i<len;i++){
        string[i]=pop(S);
    }
}

int main(){
    char string[30];
    int choice;
    while(1){
        printf("\n0.Exit\n1.Check palindrome\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 0: exit(0);
            case 1: printf("Enter the string: ");
                    scanf("%s",string);
                    reverseString(string);
                    printf("Reversed string: %s\n",string);
                    break;
            default:printf("Enter proper choice\n");
        }
    }
    return 0;
}