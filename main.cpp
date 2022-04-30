#include <iostream>
#include <time.h>

#include "population.h"

int main()
{
    srand(time(NULL));

    const char* TARGET = "hello world";
    const int POPULATION_SIZE = 100;
    const double MUTATION_RATE = 0.01f; // in %

    Population population(POPULATION_SIZE, TARGET, MUTATION_RATE);

    while (!population.nextGen());
}
