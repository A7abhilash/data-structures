#include<stdio.h>
#include <limits.h>

int V;

int minKey(int key[],int mstSet[]){
	int minValue = INT_MAX;
	int minIndex = -1;

	for (int i = 0; i < V; i++){
		if (mstSet[i] == 0 && key[i] < minValue){
			minValue = key[i];
			minIndex = i;
		}
	}

	return minIndex;
}

void printMST(int parent[],int graph[V][V]){
	int totalWeight = 0, weight;

	printf("Edge \t Weight\n");
	for (int i = 1; i < V; i++){
		weight = graph[i][parent[i]];
		totalWeight += weight;
		printf("%d -> %d \t %d\n", parent[i], i, weight);
	}

	printf("Min. spanning tree's weight: %d\n", totalWeight);
}

void primMST(int graph[V][V]){
	int parent[V];		//to store the parent of i'th index in MST.
	int key[V];			//to store the weight for each edge in MST.
	int mstSet[V];		//to store the set of vertices included in MST.

	for (int i = 0; i < V; i++){
		key[i] = INT_MAX;
		mstSet[i] = 0;
	}

	key[0] = 0;			//first vertex is picked as the source vertex.
	parent[0] = -1;		//first vertex is the root.

	for (int count = 0; count < V - 1; count++){
		int u = minKey(key, mstSet);
		mstSet[u] = 1;

		for (int v = 1; v < V; v++){
			if (graph[u][v] != 0 && mstSet[v] == 0 && graph[u][v] < key[v]){
				parent[v] = u;
				key[v] = graph[u][v];
			}
		}
	}

	printMST(parent, graph);
}

int main(){
	printf("Enter the no. of vertices: ");
	scanf("%d", &V);

	int graph[V][V];
	printf("Enter the weight of each edge in 2d matrix form of order %d x %d:\n", V, V);
	for (int i = 0; i < V; i++){
		for (int j = 0; j < V; j++){
			scanf("%d", &graph[i][j]);
		}
	}

	primMST(graph);
}