#pragma once

#include "element.h"

#include <vector>

class Population
{
private:
    int size;
    int targetLength;
    double mutationRate;
    const char* target;
    std::vector<Element*> elements;

public:
    Population(int size, const char* target, double mutationRate);
    ~Population();

    int calcFitness(char* data) const;
    bool nextGen() const;

    void logData() const;
};
