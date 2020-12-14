#include<stdio.h>
#include<stdlib.h>

struct QUEUE{
    int items[5];
    int front,rear;
};
typedef struct QUEUE queue;

queue insertRear(queue Q){
    if(Q.rear==4){
        printf("Queue is full\n");
    }else{
        printf("Enter the new item:");
        scanf("%d",&Q.items[++Q.rear]);
    }
    return Q;
}

queue insertFront(queue Q){
    if(Q.front==0 && Q.rear==4){
        printf("Queue is full\n");
    }else{
        int item;
        printf("Enter new item:");
        scanf("%d",&item);
        if(Q.front>Q.rear) {
            Q.items[++Q.rear]=item;
            printf("Item enqueued\n");
        } else if(Q.front>0) {
            Q.items[--Q.front]=item;
            printf("Item enqueued\n");
        }
        else printf("Front insertion is not possible\n");
    }
    return Q;
}

queue deleteFront(queue Q){
    if(Q.front>Q.rear) printf("Queue is empty\n");
    else printf("Dequeued item: %d\n",Q.items[Q.front++]);
    return Q;
}

queue deleteRear(queue Q){
    if(Q.front>Q.rear) printf("Queue is empty\n");
    else printf("Deleted item: %d\n",Q.items[Q.rear--]);
    return Q;
}

void displayQueue(queue Q){
     if(Q.front>Q.rear){
        printf("Queue is empty\n");
    }else{
        printf("Queue items:\n");
        for(int i=Q.front;i<=Q.rear;i++){
            printf("%d ",Q.items[i]);
        }
        printf("\n");
    }
}

int main(){
    int choice;
    queue Q;
    Q.front=0;Q.rear=-1;
    while(1){
        printf("\n0.Exit\n1.Insert Rear\n2.Insert Front\n3.Delete Front\n4.Delete Rear\n5.Display Queue\nEnter your choice:");
		scanf("%d", &choice);
        
        switch(choice){
            case 0: exit(0); break;
            case 1: Q=insertRear(Q); break;
            case 2: Q=insertFront(Q); break;
            case 3: Q=deleteFront(Q); break;
            case 4: Q=deleteRear(Q); break;
            case 5: displayQueue(Q); break;
            default: printf("Enter proper choice\n");
        }
    }
    return 0;
}