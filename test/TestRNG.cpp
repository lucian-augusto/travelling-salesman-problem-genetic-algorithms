#include "../src/RNG.hpp"
#include <cassert>
#include <cstddef>
#include <iostream>

#define MIN 1
#define MAX 10

void constructorTest() {
  std::cout << "Starting RNG Constructor Test.\n";
  RNG rng;
  assert(&rng != NULL);
  std::cout << "Constructor test passed.\n";
}

void generateNumberTest() {
  std::cout << "Starting generateNumber() test.\n";
  RNG rng;
  int num1 = rng.generateNumber(MIN, MAX);
  assert(num1 >= MIN && num1 <= MAX);

  int num2 = rng.generateNumber(MIN, MAX);
  assert(num1 >= MIN && num1 <= MAX);

  assert(num1 != num2);

  std::cout << "generateNumber() test passed.\n";
}

int main(void) {
  constructorTest();
  generateNumberTest();

  std::cout << "All RNG tests passed.\n";
  return 0;
}
