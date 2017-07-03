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
    i=0;
   /* for(i=0; i++; i<size){
    //    g->vertexList[i] = makeVertex(0, 0);
        g->vertexList[i].height = 0;
        g->vertexList[i].eFlow = 0;
    }*/

    while(i<size){
        g->vertexList[i].height = 0;
        g->vertexList[i].eFlow = 0;
        i++;
    }

    return g;
}

bool addEdge(Graph* g, int u, int v, int capacity){
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
            //residual graph things
            e = makeEdge(-e->flow, 0, e->v, s);
            addToList(g->edgeList, (void*)e);
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
* might be all sorts of glitched out
*/
void reverseFlow(Graph* g, Edge* e, int flow){
    int u = e->v;
    int v = e->u;
    Node* n = g->edgeList;
    Edge* ed;
    //takes flow from (u,v) and transfers it to the new (v,u) edge
    while(n->next!=NULL){
        n = n->next;
        ed = (Edge*)n->content;
        if(ed->v==v && ed->u==u){
            ed->flow -= flow;
            return;
        }
    }
    //ed = makeEdge(0, flow, u, v);
    ed = makeEdge(-flow, 0, u, v);
    addToList(g->edgeList, (void*)ed);
}

/**
* relabel vertex u
*/
void relabel(Graph* g, int u){
    Node* n = g->edgeList;
    Edge* e;
    int minHeight = INT_MAX;
    while(n->next!=NULL){
        n = n->next;
        e = (Edge*)n->content;
        if(e->u==u){
            //flow = capacity -> no relabel
            if(e->flow==e->capacity)
                continue;
            if(g->vertexList[e->v].height<minHeight){
                minHeight = g->vertexList[e->v].height;
                g->vertexList[u].height= minHeight+1;
            }
        }
    }
}

/**
* push flow from vertex u
*/
bool push(Graph* g, int u){
    Node* n = g->edgeList;
    Edge* e;
    int flow;

    while(n->next!=NULL){
        n = n->next;
        e = (Edge*)n->content;
        if(e->u==u){
            if(e->flow==e->capacity)
                continue;
            if(g->vertexList[u].height>g->vertexList[e->v].height){
                //min(a,b)
                flow = ((e->capacity-e->flow)<(g->vertexList[u].eFlow))?(e->capacity-e->flow):(g->vertexList[u].eFlow);
                g->vertexList[u].eFlow -= flow;
                g->vertexList[e->v].eFlow += flow;e->flow += flow;
                reverseFlow(g, e, flow);
                return true;
            }
        }
    }
    return false;
}

/**
* the main problem
*/
int getMaxFlow(Graph* g, int source, int sink){
    preflow(g, source);
    int i = vertexOverFlow(g);
    while(i!=-1){
        if(!push(g, i))
            relabel(g, i);
        i = vertexOverFlow(g);
    }
    Node* n = g->edgeList;
    while(n->next!=NULL){
        n = n->next;
        Edge* e = (Edge*)n->content;
    }
    return g->vertexList[sink].eFlow;
}


int main(){
    int n, s, t, m;
    int u, v, c;
    scanf("%d\n", &n);
    if (n <= 0) return 1;
    Graph* g = makeGraph(n);

    scanf("%d %d %d\n", &s, &t, &m);

    for (int i = 0; i < m; i++) {
      scanf("%d %d %d\n", &u, &v, &c);
      addEdge(g, u, v, c);
    }

    // Node* n = g->edgeList;
    printf("%d\n", getMaxFlow(g, s, t));
}
/*
int main(){
    Graph* g = makeGraph(6);
}*/
