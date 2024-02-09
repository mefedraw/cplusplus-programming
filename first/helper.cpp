#include <iostream>
#include <cmath>
#include "helper.h"

//first task
void change(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void change(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//second task

int without(float &a) {
    return (int)a; 
}

int without(float *a) {
    return (int)*a; 
}

//third task

void multiple(Complex &num, float &a) {
    num.re *= a;
    num.im *= a;
}

void multiple(Complex *num, float *a) {
    (*num).re *= *a;
    (*num).im *= *a;
}

//forth task

void Circle::Move(float& to_x, float& to_y) {
    x += to_x;
    y += to_y;
}
void Circle::Move(float* to_x, float* to_y) {
    x += *to_x;
    y += *to_y;
}