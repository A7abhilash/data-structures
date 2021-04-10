#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main(){
        srand(time(0));
        int n,e,pos=-1,count=0;

        printf("Enter the size: ");
        scanf("%d",&n);

        int arr[n];

        for(int i=0;i<n;i++){
                arr[i]=rand() % 2000;
        }

        printf("Array elements are:\n");
        for(int i=0;i<n;i++){
                printf("%d ",arr[i]);
        }printf("\n");

        printf("Enter the element to be searched: ")    ;
        scanf("%d",&e);

        for(int i=0;i<n;i++){
                count++;
                if(arr[i]==e){
                        pos=i+1;
                        break;
                }
        }

        if(pos==-1){
                printf("Element not found\n");
        }else{
                printf("Element found at position: %d. Count: %d\n",pos,count);
        }
}