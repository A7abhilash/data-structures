#include<stdio.h>
#include<stdlib.h>

void read(int *);
void display(int *);
void insertByOrder(int *);
void deleteByElement(int *);

int size,N=0;

void main(){
    int *a,choice;
    printf("Enter the size of array:\n");
    scanf("%d",&size);
    a=(int*)malloc(size*sizeof(int));
    while(1){
        printf("\n1.Read\n2.Display\n3.Insert\n4.Delete\n5.Exit\nEnter the choice:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:read(a);break;
            case 2:display(a);break;
            case 3:insertByOrder(a);break;
            case 4:deleteByElement(a);break;
            default:exit(0);
        }
    }
}

void read(int *arr){
    printf("Enter the no. of elements:\n");
    scanf("%d",&N);
    printf("Enter the elements:\n");
    for(int i=0;i<N;i++)
        scanf("%d",arr+i);
}

void display(int *arr){
    if(N==0){
        printf("Empty array\n");
        return;
    }
    printf("Array elements are:\n");
    for(int i=0;i<N;i++)
        printf("%d ",*(arr+i));
    printf("\n");
}

void insertByOrder(int *arr){
    if(N==size){
        printf("Array is full\n");
        size=size*2;
        arr=(int*)realloc(arr,size);
        printf("Reallocated the memory by two times\n");
    }
    int i,element;
    printf("Enter the new element:\n");
    scanf("%d",&element);
    for(i=N-1;i>=0 && *(arr+i)>element;i--){
        *(arr+i+1)=*(arr+i);
    }
    *(arr+i+1)=element;
    N++;
}

void deleteByElement(int *arr){
    if(N==0){
        printf("Empty array\n");
        return;
    }
    int i,element;
    printf("Enter the element to be deleted:\n");
    scanf("%d",&element);
    for(i=0;i<N && *(arr+i)!=element;i++);
    if(i==N){
        printf("Element doesn't exist\n");
        return;
    }
    printf("Element deleted at position: %d\n",i+1);
    for(;i<N;i++){
        *(arr+i)=*(arr+i+1);
    }
    N--;
}