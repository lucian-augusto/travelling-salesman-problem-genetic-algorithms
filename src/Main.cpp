#include "FitnessFunction.hpp"
#include "Gene.hpp"
#include "GenericAlgorithim.hpp"
#include "Graph.hpp"
#include "Individual.hpp"
#include <iostream>
#include <string>
#include <vector>

#define MUTATION_PROBABILITY 10 // in Percent
#define NUMBER_OF_ITERATIONS 20
#define NUMBER_OF_VERTICES 5
#define POPULATION_SIZE 200

std::vector<Gene> generateGenePool() {
  std::vector<Gene> genePool;
  for (int i = 0; i < NUMBER_OF_VERTICES; i++) {
    Gene gene;
    gene.gene = i;
    genePool.push_back(gene);
  }

  return genePool;
}

Graph generateGraph() {
  Graph graph(NUMBER_OF_VERTICES);
  graph.addEdge(0, 1, 1);
  graph.addEdge(0, 2, 3);
  graph.addEdge(0, 3, 4);
  graph.addEdge(0, 4, 5);

  graph.addEdge(1, 2, 1);
  // graph.addEdge(1, 3, 4);
  graph.addEdge(1, 4, 8);

  graph.addEdge(2, 3, 5);
  graph.addEdge(2, 4, 1);

  // graph.addEdge(3, 4, 2);

  return graph;
}

int main(int argc, char *argv[]) {
  std::cout << "Start\n";
  Graph problem = generateGraph();

  FitnessFunction fitnessFunction;
  fitnessFunction.setGraph(problem);

  std::vector<Gene> pool = generateGenePool();
  GeneticAlgorithim ga(POPULATION_SIZE, NUMBER_OF_ITERATIONS,
                       MUTATION_PROBABILITY, pool, pool[0], fitnessFunction);

  Individual solution = ga.execute();

  std::cout << "Best Individual Path: ";
  solution.print();
  std::cout << " | Total Weight: " + std::to_string(solution.getScore()) + "\n";

  return 0;
}
