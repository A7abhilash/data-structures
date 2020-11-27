#include<stdio.h>
#include<stdlib.h>

struct STACKNODE{
    int data;
    struct STACKNODE* link;
};
typedef struct STACKNODE* stacknode;

int isEmpty(stacknode top){
    if(top==NULL) return 1;
    return 0;
}

stacknode push(stacknode top){
    stacknode n = (stacknode)malloc(sizeof(struct STACKNODE));
    printf("Enter the data:");
    scanf("%d",&n->data);
    printf("Node item pushed\n");
    // if(isEmpty(top)) return n;
    n->link=top;
    return n;
}

stacknode pop(stacknode top){
    if(isEmpty(top)){
        printf("Stack underflow\n");
        return NULL;
    }
    stacknode temp=top;
    top = top->link;
    printf("Node item popped:%d\n",temp->data);
    free(temp);
    return top; 
}

int stackCount(stacknode top){
    if(isEmpty(top)){
        printf("Stack is empty\n");
        return 0;
    }
    stacknode temp=top;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->link;
    }
    return count;
}

int peek(stacknode top){
    if(isEmpty(top)){
        printf("Stack underflow\n");
        return 0;
    }
    return top->data; 
}

void display(stacknode top){
    if(isEmpty(top)){
        printf("Stack is empty\n");
        return;
    }
    printf("No. of items in stack:%d\n",stackCount(top));
    stacknode temp=top;
    printf("Stack:\n");
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->link;
    }
}

int main(){
    stacknode top;
    top=NULL;
    int choice;

    while(1){
        printf("\n0.Exit\n1.Push\n2.Pop\n3.Display\n4.Get peek\n5.Total items in stack\nEnter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 0: exit(0);
            case 1: top=push(top);break;
            case 2: top=pop(top);break;
            case 3: display(top);break;
            case 4: printf("Top of stack:%d\n" ,peek(top));break;
            case 5: printf("Total no. of items in stack:%d\n",stackCount(top));break;
            default:printf("Enter proper option\n");
        }
    }
    return 0;
}