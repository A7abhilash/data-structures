
#include<stdio.h>
#include<stdlib.h>

struct BOOK{
    int id;
    char title[20];
    char author[20];
    int price;
};
typedef struct BOOK book;

struct STACK{
    int top;
    book arr[5];
};
typedef struct STACK* stack;

int isEmpty(stack S){
    if(S->top==-1) return 1;
    return 0;
}

int isFull(stack S){
    if(S->top==4) return 1;
    return 0;
}

void push(stack S){
    if(isFull(S)) printf("Stack overflow\n");
    else {
        book B;
        printf("Enter the book id, title, author & cost:\n");
        scanf("%d%s%s%d",&B.id,B.title,B.author,&B.price);
        S->arr[++S->top]=B;
        printf("Book has been added to the stack.\n");
    }
}

void pop(stack S){
    if(isEmpty(S)) printf("Stack underflow\n");
    else{
        book B = S->arr[S->top--];
        printf("Book with id: %d has been removed from the stack.\n",B.id);
    }
}

void displayStack(stack S){
    if(isEmpty(S)) printf("Stack is empty\n");
    else
    {
        printf("Stack of book:\n");
        printf("Id\ttitle\t\tauthor\t\tcost\n");
        printf("---------------------------------------------------\n");
        for(int i=S->top;i>=0;i--){
            printf("%d\t%s\t\t%s\t\t%d\n",S->arr[i].id,S->arr[i].title,S->arr[i].author,S->arr[i].price);
        }
    }
    
}

int main(){
    int choice;
    stack S = (stack)malloc(sizeof(struct STACK));
    S->top=-1;

    while(1){
        printf("\n0.Exit\n1.Add new book\n2.Remove a book\n3.Display stack\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 0: free(S); exit(0);
            case 1: push(S); break;
            case 2: pop(S); break;
            case 3: displayStack(S); break;
            default: printf("Enter proper choice\n");
        }
    }
    return 0;
}