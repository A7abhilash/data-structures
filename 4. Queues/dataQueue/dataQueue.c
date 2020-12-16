#include<stdio.h>
#include<stdlib.h>

struct QUEUE{
    int items[10];
    int front,rear;
};
typedef struct QUEUE queue;

queue enqueue(int d,queue Q){
    if(Q.rear==9){
        printf("Group is full\n");
    }else{
        Q.items[++Q.rear]=d;
        printf("Data enqueued\n");
    }
    return Q;
}

void displayQueue(queue Q){
     if(Q.front>Q.rear){
        printf("Group is empty\n");
    }else{
        for(int i=Q.front;i<=Q.rear;i++){
            printf("%d ",Q.items[i]);
        }
        printf("\n");
    }
}

void displaydata(queue Q[]){
    for(int i=0;i<4;i++){
        printf("Group %d: ",(i+1)); displayQueue(Q[i]);
    }
}

int main(){
    int choice,data;
    
    queue Q[4];
    for(int i=0;i<4;i++){
        Q[i].front=0;Q[i].rear=-1;
    }

    while(1){
        printf("\n0.Exit\n1.Enter data\n2.Display group of data\nEnter your choice:");
		scanf("%d", &choice);
        
        switch(choice){
            case 0: exit(0); break;
            case 1: printf("Enter the data:"); 
                    scanf("%d",&data);
                    if(data<10) Q[0]=enqueue(data,Q[0]);
                    else if(data<19) Q[1]=enqueue(data,Q[1]);
                    else if(data<29) Q[2]=enqueue(data,Q[2]);
                    else Q[3]=enqueue(data,Q[3]);
                    break;
            case 2: displaydata(Q);
                    break;
            default: printf("Enter proper choice\n");
        }
    }
    return 0;
}