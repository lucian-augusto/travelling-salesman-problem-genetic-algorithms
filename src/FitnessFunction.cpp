#include "FitnessFunction.hpp"
#include "Gene.hpp"
#include "Graph.hpp"
#include "Individual.hpp"
#include <algorithm>
#include <climits>
#include <vector>

FitnessFunction::FitnessFunction() {
  //
}

bool compareGene(Gene g1, Gene g2) { return (g1.gene < g2.gene); }

void sortChromossome(std::vector<Gene> *chromossome) {
  std::sort(++chromossome->begin(), --chromossome->end(), compareGene);
}

bool hasDuplicatedGenes(Individual individual) {
  std::vector<Gene> chromossomeCopy = individual.getChromossome();
  sortChromossome(&chromossomeCopy);

  for (std::vector<Gene>::size_type i = 1; i < chromossomeCopy.size() - 1;
       i++) {
    if (chromossomeCopy[i].gene == chromossomeCopy[i + 1].gene) {
      return true;
    }
  }

  return false;
}

int FitnessFunction::evaluateIndividual(Individual individual) {
  if (hasDuplicatedGenes(individual)) {
    return INT_MAX;
  }

  return this->internalCalculateScore(individual);
}

void FitnessFunction::setGraph(Graph graph) { this->graph = graph; }

int FitnessFunction::internalCalculateScore(Individual individual) {
  int score = 0;
  for (std::vector<Gene>::size_type i = 0;
       i < individual.getChromossomeSize() - 1; i++) {
    int segmentScore =
        this->graph.getEdgeWeight(individual.getGeneInIndex(i).gene,
                                  individual.getGeneInIndex(i + 1).gene);
    if (segmentScore <= 0) {
      return INT_MAX;
    }

    score += segmentScore;
  }

  return score;
}
