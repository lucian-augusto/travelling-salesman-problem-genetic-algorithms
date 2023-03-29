#pragma once

#include "Graph.hpp"
#include "Individual.hpp"
#include "Population.hpp"

class FitnessFunction {
  Graph graph;

private:
  int internalCalculateScore(Individual individual);

public:
  FitnessFunction();
  int evaluateIndividual(Individual individual);
  void setGraph(Graph graph);
};
