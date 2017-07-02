#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "utils.hpp"

#include <iostream>
#include <vector>

/*****************************************/
class Vertex {
public:
  long long height, excessFlow;

  Vertex (long long h, long long eFlow) {
    this->height = h; this->excessFlow = eFlow;
  };
  virtual ~Vertex (){};
};

class Edge {
public:
  long long flow, capacity;
  long long u, v;

  Edge (long long u, long long v, long long flow, long long capacity) {
    this->flow = flow; this->capacity = capacity;
    this->u = u; this->v = v;
  };
  virtual ~Edge (){};
};

/*****************************************/

class Graph {
private:
  long long n; // |V|
  long long source, sink; // source and sink
  std::vector<Edge> edges;
  std::vector<Vertex> vertexs;

  bool addEdge(long long u, long long v, long long capacity, long long flow);

  // utils
  void initialize_preflow(long long index_source);
  long long overFlowVertex(std::vector<Vertex>& ver);
  void updateReverseEdgeFlow(long long i, long long flow);

  bool push(long long vertex_index_u);
  bool relabel(long long vertex_index_u);

public:
  Graph (long long n) {
    this->n = n;
    vertexs.resize(n, {0, 0});
  };
  virtual ~Graph (){
    std::cout << "Bye Graph" << '\n';
  };

  bool addEdge(long long u, long long v, long long capacity);
  long long pushRelabel(long long source, long long sink);
};

#endif
