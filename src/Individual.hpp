#pragma once

#include "Gene.hpp"
#include <climits>
#include <vector>

class Individual {

private:
  int score;
  int chromossomeSize;
  std::vector<Gene> chromossome;

public:
  Individual(std::vector<Gene> genePool);
  std::vector<Gene> getChromossome();
  int getChromossomeSize();
  Gene getGeneInIndex(int index);
  int getScore();
  void print();
  void setGeneByIndex(int index, Gene gene);
  void setScore(int score);
};
