#include<stdio.h>
#include<stdlib.h>

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

int isOpeningSymbol(char c){
    switch(c){
        case '(':
        case '{':
        case '[': return 1;
        default: return 0;
    }
}

int isClosingSymbol(char c){
    switch(c){
        case ')':
        case '}':
        case ']': return 1;
        default: return 0;
    }
}

int symbolMatch(char c){
    switch(c){
        case '(':
        case ')':return 1;
        case '{':
        case '}':return 2;
        case '[': 
        case ']':return 3;
        default: return 0;
    }
}

int isExpressionBalanced(char expression[]){
    stack S = (stack)malloc(sizeof(struct STACK));
    S->top=-1;
    char c;
    int i=0;
    while((c=expression[i++]) != '\0'){
        if(isOpeningSymbol(c)){
            push(c,S);
        }
        if(isClosingSymbol(c)){
            if(symbolMatch(c)!=symbolMatch(pop(S))){
                return 0;
            }
        }
    }
     return isEmpty(S)? 1: 0;
}

int main(){
    char expression[30];
    int choice;
    while(1){
        printf("\n0.Exit\n1.Check balanced expression\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 0: exit(0);
            case 1: printf("Enter the expression: ");
                    scanf("%s",expression);
                    isExpressionBalanced(expression) ? printf("Yes\n"):printf("No\n");
                    break;
            default:printf("Enter proper choice\n");
        }
    }
    return 0;
}