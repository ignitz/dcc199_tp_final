#include <iostream>
#include <vector>


// Excess Flow
typedef struct{
    long long height, eFlow;
} Vertex;

class Edge {
public:
  long long flow, capacity;

  Edge (long long flow, long long capacity) {
    this->flow = flow;
    this->capacity = capacity;
  };
  virtual ~Edge (){};
};

class Graph {
private:
  long long n; // |V|
  long long source, sink; // source and sink
  std::vector<std::vector<Edge>> edges;
  std::vector<Vertex> vertexList;

public:
  Graph (long long n, long long s, long long t) {
    this->n = n;
    this->source = s;
    this->sink = t;
    vertexList.resize(n, {0, 0});

    this->edges.resize(n);
  }
  virtual ~Graph (){
    std::cout << "Bye Graph" << '\n';
  };

  void initialize_preflow();
};

void Graph::initialize_preflow() {
  vertexList[source] = n;

}

// int main(int argc, char const *argv[]) {
int main() {
  Graph graph(6, 0, 5);

  return 0;
}
