#include "GenericAlgorithim.hpp"
#include "FitnessFunction.hpp"
#include "Gene.hpp"
#include "Individual.hpp"
#include "Population.hpp"
#include "RNG.hpp"
#include <algorithm>
#include <vector>

void addGeneToIndividualCandidatePool(std::vector<Gene> *individualCandidate,
                                      Gene gene);
bool compareIndividual(Individual individual1, Individual individual2);
void sortPopulation(std::vector<Individual> *population);

GeneticAlgorithim::GeneticAlgorithim(int populationSize, int iterations,
                                     float mutationProbability,
                                     std::vector<Gene> genePool,
                                     Gene initialGene,
                                     FitnessFunction fitnessFunction)
    : rng() {
  this->populationSize = populationSize;
  this->iterations = iterations;
  this->mutationProbability = mutationProbability;
  this->genePool = genePool;
  this->initialGene = initialGene;
  this->chromossomeSize = genePool.size() + 1;
  this->cycleCounter = 0;
  this->fitnessFunction = fitnessFunction;
}

bool GeneticAlgorithim::evaluateStopCriteria() {
  if (this->cycleCounter < this->iterations) {
    return true;
  }

  return false;
}

Individual GeneticAlgorithim::execute() {
  this->population = this->generateInitialPopulation();

  while (evaluateStopCriteria()) {
    this->cycleCounter++;
    this->executeCycle();
  }

  return this->population.getIndividualByIndex(0);
}

void GeneticAlgorithim::executeCycle() {
  std::vector<Individual> newPopulationVector;

  for (int i = 0; i < this->populationSize; i++) {
    NewParents newParents = this->selectForReproduction();
    Individual child =
        this->reproduction(newParents.parent1, newParents.parent2);
    child.setScore(this->fitnessFunction.evaluateIndividual(child));
    newPopulationVector.push_back(child);
  }

  sortPopulation(&newPopulationVector);

  this->population = Population(newPopulationVector);
}

Individual GeneticAlgorithim::generateIndividual() {
  std::vector<Gene> availablePool;
  availablePool.push_back(this->initialGene);
  for (Gene gene : this->genePool) {
    addGeneToIndividualCandidatePool(&availablePool, gene);
  }
  availablePool.push_back(this->initialGene);
  std::random_shuffle(++availablePool.begin(), --availablePool.end());
  Individual individual(availablePool);
  individual.setScore(this->fitnessFunction.evaluateIndividual(individual));
  return individual;
}

Population GeneticAlgorithim::generateInitialPopulation() {
  std::vector<Individual> prePopulation;
  for (int i = 0; i < this->populationSize; i++) {
    prePopulation.push_back(this->generateIndividual());
  }

  sortPopulation(&prePopulation);

  return Population(prePopulation);
}

void GeneticAlgorithim::includeMissingGenesToIndividualCandidate(
    std::vector<Gene> *individualCandidate) {
  while (individualCandidate->size() < this->chromossomeSize - 1) {
    for (std::vector<Gene>::size_type i = 0; i < this->chromossomeSize; i++) {
      addGeneToIndividualCandidatePool(individualCandidate, this->genePool[i]);
    }
  }
}

void GeneticAlgorithim::mutate(Individual *individual) {
  //
}

Individual GeneticAlgorithim::reproduction(Individual parent1,
                                           Individual parent2) {
  int splicePosition = this->rng.generateNumber(genePool.size() - 1);
  std::vector<Gene> childGenePool;

  for (int i = 0; i < splicePosition; i++) {
    childGenePool.push_back(parent1.getChromossome()[i]);
  }

  for (int i = splicePosition; i < parent2.getChromossomeSize() - 1; i++) {
    addGeneToIndividualCandidatePool(&childGenePool, parent2.getGeneInIndex(i));
  }

  if (childGenePool.size() < this->chromossomeSize) {
    this->includeMissingGenesToIndividualCandidate(&childGenePool);
  }

  childGenePool.push_back(genePool[0]);
  return Individual(childGenePool);
}

NewParents GeneticAlgorithim::selectForReproduction() {
  int firstParentIndex = this->rng.generateNumber(this->chromossomeSize);
  int secondParentIndex;
  do {
    secondParentIndex = this->rng.generateNumber(this->chromossomeSize);
  } while (firstParentIndex == secondParentIndex);

  NewParents newParents = {
      this->population.getIndividualByIndex(firstParentIndex),
      this->population.getIndividualByIndex(secondParentIndex)};
  return newParents;
}

void addGeneToIndividualCandidatePool(std::vector<Gene> *individualCandidate,
                                      Gene gene) {
  for (std::vector<Gene>::size_type i = 0; i < individualCandidate->size();
       i++) {
    if ((*individualCandidate)[i].gene == gene.gene) {
      return;
    }
  }

  individualCandidate->push_back(gene);
}

bool compareIndividual(Individual individual1, Individual individual2) {
  return (individual1.getScore() < individual2.getScore());
}

void sortPopulation(std::vector<Individual> *population) {
  std::sort(population->begin(), population->end(), compareIndividual);
}
