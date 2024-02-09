#include <iostream>
#include <cmath>
#include "complex.h"

Complex::Complex(Complex const& num) {
    im = num.im;
    re = num.re;
}

Complex::Complex() {
    im = re = 0;
}

Complex::Complex(float im_new, float re_new) {
    im = im_new;
    re = re_new;
}

Complex::Complex(float re_new) {
    re = re_new;
}

Complex::Complex(float im_new) {
    im = im_new;
}

void Complex :: multiple_on_number(float num) {
    im *= num;
    re *= num;
}

float Complex::length() {
    return sqrt(re*re + im*im);
}

void Complex::print() {
    std::cout << re << " " << im << "i";
}

Complex Complex :: operator*(Complex const& another) {
    Complex new_num;
    new_num.im = im * another.re + re * another.im;
    new_num.im = re * another.re - im * another.im;
    return new_num;
}

Complex Complex :: operator+(Complex const& another) {
    Complex new_num;
    new_num.im = im + another.im;
    new_num.im = re + another.re;
    return new_num;
}