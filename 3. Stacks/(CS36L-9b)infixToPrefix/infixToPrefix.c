#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct operatorStack{
    int top;
    char items[20];
};
typedef struct operatorStack* operatorStack;

void pushOperator(char c, operatorStack S){
    if(S->top==19) printf("Stack overflow\n");
    else S->items[++S->top]=c;
}

char popOperator(operatorStack S){
    if(S->top==-1) printf("Stack underflow\n");
    else return S->items[S->top--];
}

struct operandStack{
    int top;
    char items[20][20];
};
typedef struct operandStack* operandStack;

void pushOperand(char c[], operandStack S){
    if(S->top==19) printf("Stack overflow\n");
    else strcpy(S->items[++S->top],c);
}

char* popOperand(operandStack S){
    if(S->top==-1) printf("Stack underflow\n");
    else {
        char *c = S->items[S->top--];
        return c;
    }
}

int isOperator(char c){
    switch(c){
        case '+':
        case '-':
        case '*':
        case '/':
        case '(':
        case ')':
        case '$':
        case '^': return 1;
        default: return 0;
    }
}

int stackPrecedence(char c){
    switch(c){
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 4;
        case '$':
        case '^': return 6;
        case '(': return 0;
    }
}

int inputPrecedence(char c){
    switch(c){
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 3;
        case '$':
        case '^': return 7;
        case '(': return 9;
        case ')': return 0;
    }
}

void newitem(operatorStack operator, operandStack operand){
    char *oprnd2= popOperand(operand);
    char *oprnd1= popOperand(operand);
    char opr= popOperator(operator);
    char exp[20],temp[2];
    temp[0]=opr;temp[1]='\0';
    strcpy(exp,temp);
    strcat(exp,oprnd1);
    strcat(exp,oprnd2);
    pushOperand(exp,operand);
}

void infixToPrefix(char infix[],char prefix[]){
    operandStack operand = (operandStack)malloc(sizeof(struct operandStack));
    operand->top=-1;    
    operatorStack operator = (operatorStack)malloc(sizeof(struct operatorStack));
    operator->top=-1;
    char c,temp[2];int i=0;

    while ((c=infix[i++])!='\0')
    {
        if(!isOperator(c)){
            temp[0]=c;temp[1]='\0';
            pushOperand(temp,operand);
        }else{
            while(operator->top!=-1 && stackPrecedence(operator->items[operator->top])>inputPrecedence(c)){
                if(c==')'){
                    while(operator->items[operator->top]!='('){
                        newitem(operator,operand);
                    }
                    popOperator(operator);
                    break;
                }else{
                    newitem(operator,operand);
                }
            }
            if(c!=')'){
                pushOperator(c,operator);
            }
        }
    }
    while(operator->top!=-1){
        newitem(operator,operand);
    }
    strcpy(prefix,operand->items[operand->top]);
}

int main(){
    char infix[30],prefix[30];
    int choice;
    while(1){
        printf("\n0.Exit\n1.Conversion\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 0: exit(0);
            case 1: printf("Enter the infix expression:");
                    scanf("%s",infix);
                    infixToPrefix(infix,prefix);
                    printf("Prefix expression: %s \n",prefix);
                    break;
            default:printf("Enter proper choice\n");
        }
    }
    return 0;
}