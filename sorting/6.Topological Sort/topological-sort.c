#include<stdio.h>
#include<stdlib.h>

//structure for graph
struct Graph{
    int V;
    int E;
    int matrix[20][20];
    int inDegree[20];
};
typedef struct Graph graph;

graph insertNewVertex(graph G){
    if(G.V==19){
        printf("Graph matrix is full\n");
    }else{
        G.V++;
        for(int i=0;i<=G.V;i++){
            G.matrix[G.V][i]=0;
        }
		G.inDegree[G.V] = 0;
		printf("New vertex: %d added\n",G.V);
    }
    return G;
}

graph insertNewEdge(graph G){
    int i,u,v;
    printf("Enter new edge(from-->to): ");
    scanf("%d%d",&u,&v);

    if(u>=0 && u<=G.V && v>=0 && v<=G.V){
        if(G.matrix[u][v]==1){
            printf("Edge already exists\n");
        }else{
            G.matrix[u][v]=1;
			G.inDegree[v]++;
            printf("New edge(directed) added from vertex: %d to vertex: %d.\n",u,v);
            G.E++;
        }
    }else{
        printf("Invalid edge\n");
    }
    return G;
}

void topologicalSort(graph G){
    if(G.V==-1 || G.E==0){
        printf("No graph exits\n");
        return;
    }

	int stack[G.V], top = -1;
	int topologicalOrder[G.V], order = -1;
	int i, u, v, count=0;

    for (u = 0; u <= G.V; u++){
        if(G.inDegree[u]==0){
            stack[++top] = u;
        }
    }

	for (i = 0; i <= G.V; i++){
		while(top!=-1){
            count++;
			int w = stack[top--];
			topologicalOrder[++order] = w;

			for (v = 0; v <= G.V; v++){
                if(G.matrix[w][v]==1 && --G.inDegree[v]==0){
                    stack[++top] = v;
                }
            }
        }
    }

    // printf("Order: %d\n", order);
    if(order != G.V){
		printf("Graph has cycle\n");
	}else{
		printf("Topological Sort: ");
		for (i = 0; i <= G.V; i++){
			printf("%d ", topologicalOrder[i]);
		}
        printf("\nCount: %d\n", count);        
	}
}

int main(){
    graph G;
    G.V=-1;
    G.E=0;

    int choice;
    while(1){
        printf("\n0.Exit\n1.Insert new vertex\n2.Insert new edge\n3.Topological Sort\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 0: exit(0);
            case 1: G=insertNewVertex(G);break;
            case 2: G=insertNewEdge(G);break;
            case 3: topologicalSort(G); break;
            default: printf("Enter proper choice\n");
        }
    }
    return 0;
}