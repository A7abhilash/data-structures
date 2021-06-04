#include<stdio.h>

int n;

int transitiveClosure(int R[][n]){
	int i, j, k;

	for (k = 0; k < n; k++){
		for (i = 0; i < n; i++){
			if(R[i][k]==1){
				for (j = 0; j < n; j++){
					if(R[k][j]==1){
						R[i][j] = 1;
					}
				}
			}
		}
	}
}

int main(){
	int i, j;

	printf("Enter the no. of vertices: ");
	scanf("%d", &n);

	int A[n][n], R[n][n];
	printf("Enter the adjacency matrix of the graph:\n");
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			scanf("%d", &A[i][j]);
			R[i][j] = A[i][j];
		}
	}

	transitiveClosure(R);

	printf("Transitive closure: Adjacency matrix of the graph:\n");
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			printf("%d ",R[i][j]);
		}
		printf("\n");
	}

	return 0;
}