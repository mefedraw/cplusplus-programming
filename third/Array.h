#include <iostream>
#ifndef ARRAY_H
#define ARRAY_H

class Array {
private:
    int* arr;
    int size;
public:
    Array();
    Array(int size);
    Array(int* array);
    ~Array();

    int Size();
    void push_back(int num);

    bool operator<(Array& one);
    bool operator==(Array& one);
    bool operator>(Array& one);
    bool operator!=(Array& one);
    int* operator+(Array& one);
    friend std::istream& operator>>(std::istream& input, Array& arr);
};

#endif
