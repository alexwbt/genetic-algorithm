#include <iostream>
#include <time.h>

#include "population.h"

int main()
{
    srand(time(NULL));

    const char* TARGET = "102938719023871092837190827301982730918273091872309817230";
    const int POPULATION_SIZE = 100;
    const double MUTATION_RATE = 0.01f; // in %

    Population population(POPULATION_SIZE, TARGET, MUTATION_RATE);

    while (!population.nextGen());
}
