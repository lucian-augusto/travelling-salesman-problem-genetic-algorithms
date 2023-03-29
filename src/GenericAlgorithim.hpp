#pragma once

#include "FitnessFunction.hpp"
#include "Gene.hpp"
#include "Individual.hpp"
#include "Population.hpp"
#include "RNG.hpp"
#include <vector>

struct NewParents {
  Individual parent1;
  Individual parent2;
};

class GeneticAlgorithim {
  Population population;

private:
  int populationSize;
  int iterations;
  float mutationProbability;
  std::vector<Gene> genePool;
  Gene initialGene;
  int chromossomeSize;
  int cycleCounter;

  RNG rng;
  FitnessFunction fitnessFunction;

  bool evaluateStopCriteria();
  void executeCycle();
  Individual generateIndividual();
  Population generateInitialPopulation();
  void includeMissingGenesToIndividualCandidate(
      std::vector<Gene> *individualCandidate);
  void mutate(Individual *individual);
  Individual reproduction(Individual parent1, Individual parent2);
  NewParents selectForReproduction();
  void validateIndividual(Individual *individual);

public:
  GeneticAlgorithim(int populationSize, int iterations,
                    float mutationProbability, std::vector<Gene> genePool,
                    Gene initialGene, FitnessFunction fitnessFunction);
  Individual execute();
};
