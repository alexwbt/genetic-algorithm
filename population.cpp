#include "population.h"

#include <string>
#include <iostream>

struct Data {
    char* data;
    int fitness;
};

Population::Population(int size, const char* target, double mutationRate)
{
    this->size = size;
    this->target = target;
    this->mutationRate = mutationRate;
    targetLength = static_cast<int>(strlen(target));
    for (int i = 0; i < size; i++)
        elements.push_back(new Element(targetLength));
}

Population::~Population()
{
    for (int i = 0; i < size; i++)
        delete elements[i];
}

int Population::calcFitness(char* data) const
{
    int fitness = 0;
    for (int i = 0; i < targetLength + 1; i++)
        if (data[i] == target[i])
            fitness++;
    return pow(fitness, 3);
}

bool Population::nextGen() const
{
    std::vector<Data> data;
    int maxFitness = 0;
    double highestFitness = 0;
    int bestFitIndex = 0;
    for (int i = 0; i < size; i++)
    {
        data.push_back({ elements[i]->getData() });
        data[i].fitness = calcFitness(data[i].data), 2;
        maxFitness += data[i].fitness;
        if (data[i].fitness > highestFitness) {
            highestFitness = data[i].fitness;
            bestFitIndex = i;
        }
    }
    elements[bestFitIndex]->logData();
    highestFitness /= (double)pow(targetLength + 1, 3);

    // crossover
    if (highestFitness < 1)
    {
        for (int i = 0; i < size; i++)
        {
            // select parents
            int parentIndex[] = { 0, 0 };
            for (int parent = 0; parent < 2; parent++)
            {
                int r = rand() % 100;
                double counter = 0.0f;
                for (parentIndex[parent] = 0; parentIndex[parent] < size; parentIndex[parent]++)
                {
                    counter += (double)data[parentIndex[parent]].fitness;
                    double probable = counter / maxFitness;
                    if (r < probable * 100)
                        break;
                }
            }

            char* newData = new char[targetLength + 1.0];
            for (int j = 0; j < targetLength + 1; j++)
            {
                //newData[j] = data[parentIndex[j < targetLength / 2 ? 0 : 1]].data[j];
                newData[j] = data[parentIndex[rand() % 2]].data[j];

                if (j < targetLength && rand() % 1000 < mutationRate * 1000)
                {
                    int r = rand() % 95;
                    newData[j] = ' ' + r;
                }
            }
            elements[i]->setData(newData);
            delete[] newData;
        }
    }

    // delete copied data
    for (int i = 0; i < size; i++)
        delete[] data[i].data;

    return highestFitness >= 1;
}

void Population::logData() const
{
    for (int i = 0; i < size; i++)
        elements[i]->logData();
}
