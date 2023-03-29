#include "../src/Individual.hpp"
#include <cassert>
#include <iostream>
#include <vector>

#define VECTOR_SIZE 10

std::vector<Gene> generateGeneVector() {
  std::vector<Gene> vector;
  for (int i = 0; i < VECTOR_SIZE; i++) {
    Gene gene;
    gene.gene = i;
    vector.push_back(gene);
  }

  return vector;
}

void assertChromossome(std::vector<Gene> chromossome) {
  for (int i = 0; i < VECTOR_SIZE; i++) {
    assert(chromossome[i].gene == i);
  }
}

void constructorAndGettersTest() {
  Individual individual(generateGeneVector());

  assert(individual.getChromossomeSize() == VECTOR_SIZE);
  assert(individual.getGeneInIndex(0).gene == 0);
  assert(individual.getGeneInIndex(VECTOR_SIZE - 1).gene == 9);
  assertChromossome(individual.getChromossome());
}

void testSetters() {
  Individual individual(generateGeneVector());
  individual.setScore(15);
  assert(individual.getScore() == 15);
}

int main(int argc, char *argv[]) {
  std::cout << "Starting Individual Tests.";
  constructorAndGettersTest();
  std::cout << "All Individual Tests passed.";
  return 0;
}
