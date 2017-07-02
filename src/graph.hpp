#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "utils.hpp"

#include <iostream>
#include <vector>
#include <climits>

/*****************************************/
class Vertex {
public:
  int height;
  long long excessFlow;

  Vertex (int h, long long eFlow) {
    this->height = h; this->excessFlow = eFlow;
  };
  virtual ~Vertex (){};
};

class Edge {
public:
  int u, v;
  long long flow, capacity;

  Edge (int u, int v, long long flow, long long capacity) {
    this->flow = flow; this->capacity = capacity;
    this->u = u; this->v = v;
  };
  virtual ~Edge (){};
};

/*****************************************/

class Graph {
private:
  int n; // |V|
  long long source, sink; // source and sink
  std::vector<Edge> edges;
  std::vector<Vertex> vertexs;

  bool addEdge(int u, int v, long long capacity, long long flow);

  // utils
  void initialize_preflow(int index_source);
  int overFlowVertex(std::vector<Vertex>& ver);
  void updateReverseEdgeFlow(int i, long long flow);

  bool push(int u);
  bool relabel(int u);

public:
  Graph (int n) {
    this->n = n;
    vertexs.resize(n, {0, 0});
  };
  virtual ~Graph (){
    std::cout << "Bye Graph" << '\n';
  };

  bool addEdge(int u, int v, long long capacity);
  long long pushRelabel(int source, int sink);

  //DEBUG
  void printInfoGraph();
};

#endif
