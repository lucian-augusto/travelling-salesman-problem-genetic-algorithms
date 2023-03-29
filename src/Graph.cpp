#include "Graph.hpp"

Graph::Graph() : adjMatrix(1, std::vector<int>(1)) {
  //
}

Graph::Graph(int numberOfVertices)
    : adjMatrix(numberOfVertices, std::vector<int>(numberOfVertices)) {
  this->numberOfVertices = numberOfVertices;
}

void Graph::addEdge(int source, int destination, int weight) {
  if (!this->canAddEdge(source, destination)) {
    return;
  }

  this->adjMatrix[source][destination] = weight;
  this->adjMatrix[destination][source] = weight;
}

bool Graph::canAddEdge(int source, int destination) {
  if (source == destination) {
    return false;
  }

  if (this->adjMatrix[source][destination] != INITIAL_VALUE) {
    return false;
  }

  return true;
}

int Graph::getEdgeWeight(int source, int destination) {
  if (this->validateBounds(source) && this->validateBounds(destination)) {
    return this->adjMatrix[source][destination];
  }

  return -1;
}

int Graph::getNumberOfVertices() { return this->numberOfVertices; }

bool Graph::validateBounds(int vertexCandidate) {
  return vertexCandidate >= 0 &&
         vertexCandidate <= (this->numberOfVertices - 1);
}
