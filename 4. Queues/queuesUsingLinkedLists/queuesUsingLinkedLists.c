#include<stdio.h>
#include<stdlib.h>

struct QUEUENODE{
    int data;
    struct QUEUENODE *link;
};
typedef struct QUEUENODE *queuenode;

queuenode enqueue(queuenode R){
    queuenode n = (queuenode)malloc(sizeof(struct QUEUENODE));
    n->link=NULL;
    printf("Enter the data:");
    scanf("%d",&n->data);
    if(R!=NULL){
        R->link=n;
    }
    printf("Node item enqueued\n");
    return n;
}

queuenode dequeue(queuenode F){
    if(F==NULL){
        printf("Queue is empty\n");
        return NULL;
    }
    queuenode temp=F;
    printf("Dequeued node item: %d\n",temp->data);
    F=F->link;
    free(temp);
    return F;
}

void display(queuenode F){
     if(F==NULL){
        printf("Queue is empty\n");
        return;
    }
    int count=0;
    queuenode temp=F;
    printf("Queue:\n");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->link;
        count++;
    }
    printf("\nNo. of items in Queue: %d\n",count);
}


int main(){
    queuenode front =NULL;
    queuenode rear=NULL;
    int choice;

    while(1){
        printf("\n0.Exit\n1.Enqueue\n2.Dequeue\n3.Display\nEnter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 0: exit(0);
            case 1: rear=enqueue(rear);
                    if(front==NULL) front=rear;
                    break;
            case 2: front=dequeue(front);
                    if(front==NULL) rear=front;
                    break;
            case 3: display(front);break;
            default:printf("Enter proper choice\n");
        }
    }
    return 0;
}