#pragma once

#include "Individual.hpp"
#include <vector>

class Population {
private:
  int size;
  std::vector<Individual> individuals;

public:
  Population();
  Population(std::vector<Individual> individuals);
  Individual getIndividualByIndex(int index);
};
