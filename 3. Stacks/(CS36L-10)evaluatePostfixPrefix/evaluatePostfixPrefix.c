#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct operandStack{
    int top;
    float items[20];
};
typedef struct operandStack* operandStack;

void push(float n, operandStack S){
    if(S->top==19) printf("Stack overflow\n");
    else S->items[++S->top]=n;
}

float pop(operandStack S){
    if(S->top==-1) printf("Stack underflow\n");
    else return S->items[S->top--];
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

float compute(float a,float b,char optr){
    switch(optr){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
        case '$': 
        case '^': return pow(a,b);
        default:  printf("Invalid expression\n");
    }
}

void evaluatePostfix(char postfix[]){
    operandStack S = (operandStack)malloc(sizeof(struct operandStack));
    S->top=-1;
    char c;
    float oprnd1,oprnd2,result;
    int i=0;

    while((c=postfix[i++])!='\0'){
        if(!isOperator(c)){
            push(c-'0',S);
        }else{
            oprnd2=pop(S);
            oprnd1=pop(S);
            result=compute(oprnd1,oprnd2,c);
            push(result,S);
        }
    }

    result=pop(S);
    if(S->top!=-1) printf("Invalid expression\n");
    else printf("Value: %f\n",result);
    free(S);
}

void evaluatePrefix(char prefix[]){
    operandStack S = (operandStack)malloc(sizeof(struct operandStack));
    S->top=-1;
    char c;
    float oprnd1,oprnd2,result;
    int i=strlen(prefix)-1;
    
    while(i>=0){
        c = prefix[i];
        if(!isOperator(c)){
            push(c-'0',S);
        }else{
            oprnd1=pop(S);
            oprnd2=pop(S);
            result=compute(oprnd1,oprnd2,c);
            push(result,S);
        }
        i--;
    }

    result=pop(S);
    if(S->top!=-1) printf("Invalid expression\n");
    else printf("Value: %f\n",result);
    free(S);
}


int main(){
    char expression[30];
    int choice;
    while(1){
        printf("\n0.Exit\n1.Evaluate Postfix expression\n2.Evaluate Prefix expression\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 0: exit(0);
            case 1: printf("Enter the postfix expression:");
                    scanf("%s",expression);
                    evaluatePostfix(expression);
                    break;
            case 2: printf("Enter the prefix expression:");
                    scanf("%s",expression);
                    evaluatePrefix(expression);
                    break;
            default: printf("Enter proper choice\n");
        }
    }
}