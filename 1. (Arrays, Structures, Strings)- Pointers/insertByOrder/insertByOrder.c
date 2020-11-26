#include<stdio.h>

int n=0;

void insert_by_order(int a[],int element){
    int i,*ptr=a;
    for(i=n-1;i>=0 && *(ptr+i)>element;i--){
        *(ptr+i+1)=*(ptr+i);
    }
    *(ptr+i+1)=element;
    n++;
}

void main(){
    int a[10],i,element;
    
    printf("Enter the size of the array:\n");
    scanf("%d",&n);
    
    printf("Enter the array elements in ascending order:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    
    printf("Array elements are:\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    

    printf("\nEnter the new element\n");
    scanf("%d",&element);

    insert_by_order(a,element);

    printf("Array elements in new insertion are:\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}
