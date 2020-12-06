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

int isPalindrome(char string[]){
    stack S = (stack)malloc(sizeof(struct STACK));
    S->top=-1;
    char c;
    int i,len=strlen(string);

    for(i=0;i<len/2;i++){
        push(string[i],S);
    }
    
    if(len%2!=0) i++;

    while(i<len){
        if(string[i]!=pop(S)) return 0;
        i++;
    }
    return 1;
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
                    isPalindrome(string) ? printf("Yes\n"):printf("No\n");
                    break;
            default:printf("Enter proper choice\n");
        }
    }
    return 0;
}