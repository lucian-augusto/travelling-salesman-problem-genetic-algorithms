#include "RNG.hpp"
#include <cstddef>
#include <cstdlib>
#include <ctime>

RNG::RNG() { srand(::time(NULL)); }

int RNG::generateNumber(int max) { return this->generateNumber(0, max); }

int RNG::generateNumber(int min, int max) {
  return (rand() % (max - min + 1)) + min;
}
