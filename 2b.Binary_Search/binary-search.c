#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main(){
	srand(time(0));

	int n,e,pos=-1,count=0;

	printf("Enter the size: ");
	scanf("%d", &n);

	int arr[n], first=0,last=n-1,mid;
	arr[0]=rand() % 100;
	for(int i=1;i<n;i++){
		arr[i]=arr[i-1] + rand() % 100;
	}

	printf("Array elements are:\n");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}printf("\n");

	printf("Enter the element to be searched: ")    ;
	scanf("%d",&e);

	while(first<=last){
		count++;
		mid=(first+last)/2;
		if(arr[mid]==e){
				pos=mid+1;
				break;
		}
		if(arr[mid]<=e) first=mid+1;
		else last=mid-1;
	}

	if(pos==-1){
		printf("Element not found\n");
	}else{
		printf("Element found at position: %d. Count: %d\n",pos,count);
	}
}