#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int visited[MAX];

struct node
{
    int vertex;
    struct node *next;
};

struct Graph
{
    int numVertices;
    struct node **adjlists;
};

struct node *createNode(int v)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->vertex=v;
    newnode->next=NULL;
    return newnode;
}

struct Graph *createGraph(int vertices)
{
    struct Graph *graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices=vertices;
    graph->adjlists=(struct node**)malloc(vertices * sizeof(struct node*));
    for(int i=0;i<vertices;i++)
    {
        graph->adjlists[i]=NULL;
        visited[i]=0;
    }
    return graph;
}

void addEdge(struct Graph *graph,int src,int dest)
{
    struct node *newnode=createNode(dest);
    newnode->next=graph->adjlists[src];
    graph->adjlists[src]=newnode;
    newnode=createNode(src);
    newnode->next=graph->adjlists[dest];
    graph->adjlists[dest]=newnode;
}

void resetVisited(int vertices)
{
    for(int i=0;i<vertices;i++)
    {
        visited[i]=0;
    }
}

void BFS(struct Graph *graph, int startVertex)
{
    int queue[MAX];
    int front=0,rear=0;

    resetVisited(graph->numVertices);

    visited[startVertex]=1;
    queue[rear++]=startVertex;

    while(front != rear)
    {
        int currentVertex=queue[front++];
        printf("%d ",currentVertex);

        struct node *temp=graph->adjlists[currentVertex];
        while(temp)
        {
            int adjVertex=temp->vertex;
            if(!visited[adjVertex])
            {
                visited[adjVertex]=1;
                queue[rear++]=adjVertex;
            }
            temp=temp->next;
        }
    }
    printf("\n");
}

void DFS(struct Graph *graph, int startVertex)
{
    struct node *adjList = graph->adjlists[startVertex];
    struct node *temp = adjList;

    visited[startVertex]=1;
    printf("%d ",startVertex);

    while(temp)
    {
        int connectedVertex = temp->vertex;
        if(!visited[connectedVertex])
        {
            DFS(graph, connectedVertex);
        }
        temp=temp->next;
    }
}

int main()
{
    int vertices=6;
    struct Graph *graph=createGraph(vertices);
    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,1,3);
    addEdge(graph,2,4);
    addEdge(graph,3,4);
    addEdge(graph,3,5);

    printf("BFS Traversal starting from node 0:\n");
    BFS(graph,0);

    printf("DFS Traversal starting from node 0:\n");
    resetVisited(vertices);
    DFS(graph,0);
    printf("\n");

    return 0;
}
