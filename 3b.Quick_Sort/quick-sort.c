#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count=0;

int partition(int arr[],int start,int end){
	int pivot=arr[end];		// End element is chosen as pivot in our program
	int pIndex=start;
	int temp;
	
	for(int i=start;i<end;i++){
		count++;
		if(arr[i]<=pivot){
			//swap arr[i] & arr[pIndex]
			temp=arr[i];
			arr[i]=arr[pIndex];
			arr[pIndex]=temp;
			
			pIndex++;
		}
	}
	
	//swap arr[e] & arr[pIndex]
	temp=arr[end];
	arr[end]=arr[pIndex];
	arr[pIndex]=temp;
	
	return pIndex;
}

void quickSort(int arr[],int start,int end){
	if(start<end){
		int p=partition(arr,start,end);
		quickSort(arr,start,p-1);			//Recursice QS call for left partition
		quickSort(arr,p+1,end);			//Recursive QS call for right partition
	}
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
	
	quickSort(arr,0,n-1);
	
	printf("Sorted Array: \n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\nCount: %d",count);
	
	return 0;
}
