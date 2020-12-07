#include<stdio.h>

void reverse(int *arr,int n){
    for(int *start=arr,*end=arr+n-1;start<arr+n/2;start++,end--){   
        int temp=*start;
        *start=*end;
        *end=temp;
    }
}

int main(){
    int a[10],*ptr,n;
    printf("Enter the size of the array: \n");
    scanf("%d",&n);

    printf("Enter the array elements: \n");
    for(ptr=a;ptr<a+n;ptr++){
        scanf("%d",ptr);
    }
    printf("\nArray elements: \n");
    for(ptr=a;ptr<a+n;ptr++){
        printf("%d ",*ptr);
    }
    
    reverse(a,n);

    printf("\nReversed Array elements: \n");
    for(ptr=a;ptr<a+n;ptr++){
        printf("%d ",*ptr);
    }
    printf("%d ",*ptr);
    printf("\n");
    return 0;
}