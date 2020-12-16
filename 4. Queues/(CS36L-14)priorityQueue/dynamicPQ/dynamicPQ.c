#include<stdio.h>
#include<stdlib.h>

int SIZE=2;

struct QUEUE{
    int *items;
    int front,rear;
};
typedef struct QUEUE* queue;

queue enqueue(queue Q){
    if(Q->rear==SIZE-1){
        SIZE*=2;
        Q->items=(int*)realloc(Q->items,SIZE*sizeof(int));
        printf("Reallocated queue size\n");
    }
    printf("Enter the new item:");
    scanf("%d",&Q->items[++Q->rear]);
    printf("Item enqueued\n");

    return Q;
}

queue dequeue(queue Q){
    if(Q->front>Q->rear){
        printf("Queue is empty\n");
    }else{
        int minI=0,min=Q->items[0],i;
        for(i=Q->front;i<=Q->rear;i++){
            if(Q->items[i]<min){
                min=Q->items[i];
                minI=i;
            }
        }
        for(i=minI;i<Q->rear;i++){
            Q->items[i]=Q->items[i+1];
        }
        Q->rear--;
        printf("Dequeued item: %d\n",min);
    }
    return Q;
}

void displayQueue(queue Q){
     if(Q->front>Q->rear){
        printf("Queue is empty\n");
    }else{
        printf("Queue items:\n");
        for(int i=Q->front;i<=Q->rear;i++){
            printf("%d ",Q->items[i]);
        }
        printf("\n");
    }
}

int main(){
    int choice;
    queue Q=(queue)malloc(sizeof(struct QUEUE));
    Q->items=(int*)malloc(SIZE*sizeof(int));
    Q->front=0;Q->rear=-1;
    while(1){
        printf("\n0.Exit\n1.Enqueue\n2.Dequeue\n3.Display Queue\nEnter your choice:");
		scanf("%d", &choice);
        
        switch(choice){
            case 0: exit(0); break;
            case 1: Q=enqueue(Q); break;
            case 2: Q=dequeue(Q); break;
            case 3: displayQueue(Q); break;
            default: printf("Enter proper choice\n");
        }
    }
    return 0;
}