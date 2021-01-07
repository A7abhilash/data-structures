#include<stdio.h>
#include<stdlib.h>

struct HEAP{
    int *arr;
    int count;
    int capacity;
};
typedef struct HEAP* heap;

int parentIndex(heap H,int i){
    if(i<=0 || i>=H->count) return -1;
    return (i-1)/2;
}

int leftChildIndex(heap H,int i){
    int left=2*i+1;
    if(left>=H->count) return -1;
    return left;
}

int rightChildIndex(heap H,int i){
    int right=2*i+2;
    if(right>=H->count) return -1;
    return right;
}

void getMaxElement(heap H){
    if(H->count==0) {
        printf("Heap is empty");
    }
    printf("Max element: %d\n",H->arr[0]);
}

void swap(int *a,int *b){
    int c=*a;
    *a=*b;
    *b=c;
}

//Heapifying the element(at location i) downwards.
heap percolateDown(heap H,int i){
    int max,temp;
    int left=leftChildIndex(H,i);
    int right=rightChildIndex(H,i);

    if(left!=-1 && H->arr[left]>H->arr[i])
        max=left;
    else max=i;
    if(right!=-1 && H->arr[right]>H->arr[max])
        max=right;
    
    if(max!=i){
        //swap elements at i & max
        swap(&H->arr[i],&H->arr[max]);
        return percolateDown(H,max);
    }
    return H;
}

heap insert(heap H){
    if(H->count==H->capacity){
        H->capacity*=2;
        H->arr=(int*)realloc(H->arr,sizeof(int)*H->capacity);
        printf("Memory reallocated\n");
    }
    H->count++;
    int data,temp;
    printf("Enter the new data:");
    scanf("%d",&data);

    int i=H->count-1;
    //percolate up
    while(i>=0 && data>H->arr[parentIndex(H,i)]){
        //swap elements at i & it's parent
        swap(&H->arr[i],&H->arr[parentIndex(H,i)]);
        i=parentIndex(H,i);
    }
    H->arr[i]=data;
    printf("New data inserted\n");
    H=percolateDown(H,0);
    return H;
}

heap deleteMax(heap H){
    if(H->count==0){
        printf("Heap is empty\n");
        return H;
    }
    int data=H->arr[0];
    H->arr[0]=H->arr[--H->count];
    H=percolateDown(H,0);
    printf("Deleted Max element: %d\n",data);
    return H;
}

void displayHeap(heap H){
    if(H->count==0){
        printf("Heap is empty\n");
        return;
    }
    printf("Heap: ");
    for(int i=0;i<H->count;i++){
        printf("%d ",H->arr[i]);
    }
    printf("\n");
}

int main(){
    heap H = (heap)malloc(sizeof(struct HEAP));
    H->count=0;
    H->capacity=1;
    H->arr=(int*)malloc(H->capacity*sizeof(int));
    int choice;

    while(1){
        printf("\0.Exit\n1.Insert\n2.Display\n3.Delete\nEnter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 0: exit(0);
            case 1: H=insert(H); break;
            case 2: displayHeap(H); break;
            case 3: H=deleteMax(H); break;
            case 4: getMaxElement(H); break;
            default: printf("Enter proper choice\n");
        }
    }
    return 0;
}