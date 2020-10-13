#pragma once

class Element
{
private:
    char* data;
    int length;

public:
    Element(int length);
    ~Element();

    void setData(char* data) const;
    char* getData() const;
    void logData() const;
};
