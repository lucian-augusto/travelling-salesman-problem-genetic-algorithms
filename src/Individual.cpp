#include "Individual.hpp"
#include "Gene.hpp"
#include <climits>
#include <iostream>
#include <string>
#include <vector>

Individual::Individual(std::vector<Gene> genePool) {
  this->chromossome = genePool;
  this->chromossomeSize = this->chromossome.size();
  this->score = INT_MAX;
}

std::vector<Gene> Individual::getChromossome() { return this->chromossome; }

int Individual::getChromossomeSize() { return this->chromossomeSize; }

Gene Individual::getGeneInIndex(int index) { return this->chromossome[index]; }

int Individual::getScore() { return this->score; }

void Individual::print() {
  for (std::vector<Gene>::size_type i = 0; i < this->chromossomeSize; i++) {
    std::cout << std::to_string(this->chromossome[i].gene) + " ";
  }
}

void Individual::setScore(int score) { this->score = score; }
