#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubbleSort(int arr[],int n)
{
	int i,j;
	int rounds=0,count=0;

	for(i=1;i<n;i++)				// i=0 ; i<n ; i++ 
	{
		rounds++;
		for(j=i;j>=0;j--)			// j=0 ; j<n-i-1 ; j++
		{
			if(arr[j]>arr[j+1])
			{
                count++;
				
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
		
		if(count==0)
			break;
	}
	printf("No. of rounds: %d\n",rounds);
	printf("Sorted Array: \n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\nCount: %d",count);
}

int main()
{
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
	
	bubbleSort(arr,n);
	return 0;
}
