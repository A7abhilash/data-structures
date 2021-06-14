#include<stdio.h>

int max(int a,int b){
	return a > b ? a : b;
}

int knapSack(int i,int j,int price[],int weights[]){
	if(i==0||j==0){
		return 0;
	}

	if(weights[i-1]>j){
		return knapSack(i - 1, j, price, weights);
	}

	return max(knapSack(i - 1, j, price, weights), price[i - 1] + knapSack(i - 1, j - weights[i - 1], price, weights));
}

int main(){
	int n;
	printf("Enter the no. of items: ");
	scanf("%d", &n);
	
	int price[n], weights[n];
	printf("Enter the weight and it's price:\n");
	for (int i = 0; i < n; i++){
		printf("Item %d: ", (i + 1));
		scanf("%d%d", &weights[i], &price[i]);
	}

	int M;
	printf("Enter the max capacity of the knapsack: ");
	scanf("%d", &M);

	printf("Max profit: %d\n", knapSack(n, M, price, weights));
}