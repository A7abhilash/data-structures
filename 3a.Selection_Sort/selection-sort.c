#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selectionSort(int arr[],int n){
    int count=0,i,j; 

	for(i=0;i<n-1;i++)
	{
		int min=i;
		
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min]){
				min=j;
                count++;
            }
		}
		
		if(i!=min)
		{
			int temp=arr[i];
			arr[i]=arr[min];
			arr[min]=temp;
		}
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

	selectionSort(arr,n);
	
	return 0;
}


