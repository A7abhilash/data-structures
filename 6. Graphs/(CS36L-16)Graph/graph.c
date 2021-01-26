#include<stdio.h>
#include<stdlib.h>

//structure for graph
struct Graph{
    int V;
    int E;
    int matrix[20][20];
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
            G.matrix[v][u]=1;
            printf("New edge(undirected) added between vertex: %d and vertex: %d.\n",u,v);
            G.E++;
        }
    }else{
        printf("Invalid edge\n");
    }
    return G;
}

void DFS(graph G,int u, int isVisited[]){
    printf("%d ",u);
    isVisited[u]=1;

    for(int v=0;v<=G.V;v++){
        if(isVisited[v]==0 && G.matrix[u][v]==1){
            DFS(G,v,isVisited);
        }
    }
}

void DFSTraversal(graph G){
    int isVisited[G.V];
    for(int i=0;i<=G.V;i++){
        isVisited[i]=0;
    }
    
    for(int i=0;i<=G.V;i++){
        if(isVisited[i]==0){
            DFS(G,i,isVisited);
        }
    }
}

//structure for queue
typedef struct{
    int arr[100];
    int front;
    int rear;
}queue;


void BFS(graph G,int u, int isVisited[],queue *Q){
    Q->arr[++Q->rear]=u;//Enqueue

    while(Q->front!=Q->rear){
        int v=Q->arr[++Q->front];//Dequeue
        printf("%d ",v);
        isVisited[v]=1;

        for(int i=0;i<=G.V;i++){
            if(isVisited[i]==0 && G.matrix[v][i]==1){
                isVisited[i]=1;
                Q->arr[++Q->rear]=i;//Enqueue
            }
        }
    }
}

void BFSTraversal(graph G){
    int isVisited[G.V];
    for(int i=0;i<=G.V;i++){
        isVisited[i]=0;
    }
    queue Q;
    Q.front=Q.rear=-1;
    
    BFS(G,0,isVisited,&Q);
}

void displayGraph(graph G){
    if(G.V==-1 || G.E==0){
        printf("No graph exits\n");
        return;
    }
    printf("DFS: "); DFSTraversal(G);
    printf("\nBFS: "); BFSTraversal(G);
    printf("\n");
}

int main(){
    graph G;
    G.V=-1;
    G.E=0;

    int choice;
    while(1){
        printf("\n0.Exit\n1.Insert new vertex\n2.Insert new edge\n3.Display graph\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 0: exit(0);
            case 1: G=insertNewVertex(G);break;
            case 2: G=insertNewEdge(G);break;
            case 3: displayGraph(G); break;
            default: printf("Enter proper choice\n");
        }
    }
    return 0;
}