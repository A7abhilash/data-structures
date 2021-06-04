#include<stdio.h>

int n;

int min(int a,int b){
	return a > b ? b : a;
}

void allPairsShortestPath(int D[][n]){
	int i, j, k;

	for (k = 0; k < n; k++){
		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++){
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}
}

int main(){
	int i, j;

	printf("Enter the no. of vertices: ");
	scanf("%d", &n);

	int A[n][n], D[n][n];
	printf("Enter the adjacency matrix(with the weights corresponding edges)of the graph\n");
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			scanf("%d", &A[i][j]);
			D[i][j] = A[i][j];
		}
	}

	allPairsShortestPath(D);

	printf("All pairs shortest path: Adjacency matrix(with the weights corresponding edges) of the graph:\n");
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			printf("%d ",D[i][j]);
		}
		printf("\n");
	}

	return 0;
}