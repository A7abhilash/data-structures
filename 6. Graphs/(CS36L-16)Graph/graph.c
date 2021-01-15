#include<stdio.h>
#include<stdlib.h>

//structure for graph
struct Graph{
    int V;
    int E;
    int **matrix;
};
typedef struct Graph graph;

graph readGraph(graph G){
    int i,u,v;
    printf("No. of vertices: ");
    scanf("%d",&G.V);
    printf("No. of edges: ");
    scanf("%d",&G.E);
    G.matrix=(int**)malloc(G.V*G.V*sizeof(int));

    for(u=0;u<G.V;u++){
        for(v=0;v<G.V;v++){
            // G.matrix[u][v]=0;
            *(G.matrix+u*G.V+v)=0;
        }   
    }

    for(i=0;i<G.E;i++){
        printf("Mark edge no. %d\n",(i+1));
        printf("From vertex: ");
        scanf("%d",&u);
        printf("To vertex: ");
        scanf("%d",&v);
        *(G.matrix+u*G.V+v)=1;
        *(G.matrix+v*G.V+u)=1;
    }
    return G;
}

void DFS(graph G,int u, int isVisited[]){
    isVisited[u]=1;

    for(int v=0;v<G.V;v++){
        if(isVisited[v]==0 && *(G.matrix+u*G.V+v)==1){
            DFS(G,v,isVisited);
        }
    }
}

void DFSTraversal(graph G){
    int isVisited[G.V];
    for(int i=0;i<G.V;i++){
        isVisited[i]=0;
    }
    
    for(int i=0;i<G.V;i++){
        if(isVisited[i]==0){
            DFS(G,i,isVisited);
        }
    }
}

void BFS(graph G,int u, int isVisited[]){
    //custom queue
    int queue[G.V];
    int front=0,rear=-1;

    queue[++rear]=u;//Enqueue

    while(front<=rear){
        int v=queue[front++];//Dequeue
        printf("%d ",v);
        isVisited[v]=1;

        if(isVisited[v]==0 && *(G.matrix+u*G.V+v)==1){
            queue[++rear]=v;//Enqueue
        }
    }
}

void BFSTraversal(graph G){
    int isVisited[G.V];
    for(int i=0;i<G.V;i++){
        isVisited[i]=0;
    }
    
    for(int i=0;i<G.V;i++){
        if(isVisited[i]==0){
            BFS(G,i,isVisited);
        }
    }
}

void displayGraph(graph G){
    if(G.V==0){
        printf("No graph exits\n");
        return;
    }
    printf("DFS: "); DFSTraversal(G);
    printf("BFS: "); BFSTraversal(G);
}

int main(){
    graph G = (graph*)malloc(sizeof(struct Graph));
    G.E=G.V=0;

    int choice;
    while(1){
        printf("\n0.Exit\n1.Read new graph\n2.Display graph\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 0: exit(0);
            case 1: G=readGraph(G);break;
            case 2: displayGraph(G); break;
            default: printf("Enter proper choice\n");
        }
    }
    return 0;
}