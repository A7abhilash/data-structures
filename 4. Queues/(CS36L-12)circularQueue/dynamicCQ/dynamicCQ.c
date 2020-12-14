#include<stdio.h>
#include<stdlib.h>

int SIZE= 2;

struct QUEUE{
    int *items;
    int front,rear;
    int count;
};
typedef struct QUEUE* queue;

queue enqueue(queue Q){
    if(Q->count==SIZE){
        SIZE*=2;
        Q->items=(int*)realloc(Q->items,SIZE*sizeof(int));
        printf("Reallocated the queue size\n");
    }
    printf("Enter the new item:");
    Q->rear=(Q->rear+1)%SIZE;
    scanf("%d",&Q->items[Q->rear]);
    Q->count++;
    printf("Item enqueued\n");
    return Q;
}

queue dequeue(queue Q){
    if(Q->count==0){
        printf("Queue is empty\n");
    }else{
        printf("Dequeued item: %d\n",Q->items[Q->front]);
        Q->front=(Q->front+1)%SIZE;
        Q->count--;
    }
    return Q;
}

void displayQueue(queue Q){
     if(Q->count==0){
        printf("Queue is empty\n");
    }else{
        int i,j=Q->front;
        printf("Queue items:\n");
        for(int i=1;i<=Q->count;i++){
            printf("%d ",Q->items[j]);
            j=(j+1)%SIZE;
        }
        printf("\n");
    }
}

int main(){
    int choice;
    queue Q = (queue)malloc(sizeof(struct QUEUE));
    Q->items = (int*)malloc(SIZE*sizeof(int));
    Q->front=0;Q->rear=-1,Q->count=0;
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