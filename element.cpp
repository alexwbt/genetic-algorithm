#include "element.h"

#include <iostream>

Element::Element(int length)
{
    this->length = length;
    data = new char[length + 1.0];
    for (int i = 0; i < length; i++)
    {
        int r = rand() % 95;
        data[i] = ' ' + r;
    }
    data[length] = '\0';
}

Element::~Element()
{
    delete[] data;
}

void Element::setData(char* data) const
{
    for (int i = 0; i < length + 1; i++)
        this->data[i] = data[i];
}

char* Element::getData() const
{
    char* copy = new char[length + 1.0];
    for (int i = 0; i < length + 1; i++)
        copy[i] = data[i];
    return copy;
}

void Element::logData() const
{
    std::cout << data << std::endl;
}
