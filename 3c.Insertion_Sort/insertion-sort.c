#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertionSort(int arr[],int n){
	int i,j,key,count=0;
	
	for(i=0;i<n;i++){
		key=arr[i];
		j=i-1;
		
		while(j>=0 && arr[j]>key){
			arr[j+1]=arr[j];
			j=j-1;
            count++;
		}
		
		arr[j+1]=key;
	}
	printf("Sorted Array: \n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\nCount: %d",count);
}

int main(){
	srand(time(0));
	int i,n;
	
	printf("Enter the size \n");
	scanf("%d",&n);
	
    int arr[n];
	for(int i=0;i<n;i++){
		arr[i]=rand() % 20000;
	}

	printf("Array elements are:\n");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}printf("\n");
	
	insertionSort(arr,n);

	return 0;
}
