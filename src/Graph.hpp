#pragma once

#include <vector>

#define NO_EDGE_BETWEEN -1
#define INITIAL_VALUE 0
#define SAME_VERTEX 0

class Graph {
  int numberOfVertices;
  std::vector<std::vector<int> > adjMatrix;

private:
  bool canAddEdge(int source, int destination);
  bool validateBounds(int vertexCandidate);

public:
  Graph();
  Graph(int numberOfVertices);
  void addEdge(int source, int destination, int weight);
    int getEdgeWeight(int source, int destination);
    int getNumberOfVertices();
};
