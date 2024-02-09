#include <iostream>
#include "Array.h"

Array::Array(int* array) {
    int* temp = new int[sizeof(array) / sizeof(array[0])];
    for(int i = 0; i < sizeof(array) / sizeof(array[0]); ++i) {
        temp[i] = array[i];
        ++size;
    }

    delete[] arr;
    arr = temp;
}

Array::Array() {
    size = 0;
}

Array::Array(int sz) {
    arr = new int[sz];
}

Array::~Array() {
    delete[] arr;
}

void Array::push_back(int v) {
    int* temp = new int[size + 1];
    for (size_t i = 0; i < size; i++) {
        temp[i] = arr[i];
    }
    temp[size] = v;
    delete[] arr;
    arr = temp;
    size++;
}

int Array::Size() {
    return size;
}

bool Array::operator<(Array const& one) {
    return size < one.size;
}

bool Array::operator==(Array const& one) {
    return size == one.size;
}

bool Array::operator>(Array const& one) {
    return size > one.size;
}

bool Array::operator!=(Array const& one) {
    return size != one.size;
}

int* Array::operator+(Array const& one) {
    int* result = new int[(int)size + (int)one.size];
    int i = 0;
    for (; i < size; ++i) {
        result[i] = arr[i];
    }
    for (int j = 0; j < one.size; ++j) {
        result[i] = one.arr[j];
        ++i;
    }

    return result;
}

std::istream& operator>>(std::istream& input, Array& arr) {

    int sz;
    input >> sz;

    for (int i = 0; i < sz; ++i) {
        int num;
        input >> num;
        arr.push_back(num);
    }

    return input;
}