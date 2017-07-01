#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct Node{
    void* content;
    struct Node* next;
}Node;

typedef struct{
	int flow, capacity;
    //vertex u -> vertex v
    int u, v;
}Edge;

typedef struct{
    int height, eFlow;
} Vertex;

typedef struct{
    int size;
    //be careful with the void pointers
    //first node's content is always null
    Vertex* vertexList;
    Node* edgeList;
}Graph;

Node* makeNode(void* content){
    Node* n = (Node*)malloc(sizeof(Node));
    n->next = NULL;
    n->content = content;
    return n;
}

bool addToList(Node* list, void* content){
    Node* first = list;
    while(list->next!=NULL){
        list = list->next;
        if(first==list) //cycle detection, looped back to the first node
            return false;
    }
    list->next = makeNode(content);
    return true;
}

Edge* makeEdge(int flow, int capacity, int u, int v){
    Edge* e = (Edge*)malloc(sizeof(Edge));
    e->flow = flow;
    e->capacity = capacity;
    e->u = u;
    e->v = v;
    return e;
}

Vertex makeVertex(int height, int eFlow){
    Vertex v;
    v.height = height;
    v.eFlow = eFlow;
    return v;
}

/**
* size>0
*/
Graph* makeGraph(int size){
    int i;
    
    if(size<=0) //needs to have at least one vertex
        return NULL;

    Graph* g = (Graph*)malloc(sizeof(Graph));
    Node* n = (Node*)malloc(sizeof(Node));

    g->size = size;
    g->vertexList = (Vertex*)malloc(size*sizeof(Vertex));
    g->edgeList = makeNode(NULL);

    for(i=0; i++; i<size){
        g->vertexList[i] = makeVertex(0, 0);
    }

    return g;
}

bool addEdge(Graph* g, int capacity, int u, int v){
    bool success = addToList(g->edgeList, (void*)makeEdge(0, capacity, u, v));
    if(success)
        return true;
    else
        return false;
}

void preflow(Graph* g, int s){
    Node* n = g->edgeList;
    Edge* e;
    g->vertexList[s].height = g->size;

    while(n->next!=NULL){
        n = n->next;
        e = (Edge*)n->content;
        if(e->u==s){
            e->flow = e->capacity;
            g->vertexList[e->v].eFlow = e->flow;
        }
    }
}

int vertexOverFlow(Graph* g){
    int i;
    for(i=1; i<g->size-1; i++){
        if(g->vertexList[i].eFlow>0)
            return i;
    }
    //no overflowing vertexes
    return -1;
}

/**
* push flow from vertex u
*/
bool push(Graph* g, int u){

}

/**
* relabel vertex u
*/
bool relabel(Graph* g, int u){

}

/**
* the main problem
*/
int getMaxFlow(Graph* g, int source, int sink){

}


int main(){}
