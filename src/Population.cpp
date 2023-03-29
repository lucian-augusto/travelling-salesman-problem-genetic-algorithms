#include "Population.hpp"
#include "Individual.hpp"
#include <vector>

Population::Population() {
  //
}

Population::Population(std::vector<Individual> individuals) {
  this->individuals = individuals;
}

Individual Population::getIndividualByIndex(int index) {
  return this->individuals[index];
}
