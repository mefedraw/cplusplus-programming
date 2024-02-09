#include <iostream>
#include "helper.h"


int main() {
    // first
    int a = 1;
    int b = 2;
    int a_a = 3;
    int b_b = 4;
    change(a_a, b_b);
    change(&a, &b);

    //second
    float q = 1.5;
    float q_q = 1.5;
    int new_q = without(q);
    int new_q_q = without(&q_q);

    //third
    Complex new_n;
    new_n.im = 3;
    new_n.re = 5;
    multiple(new_n, 5.0);
    multiple(&new_n, 5.0);

    // forth

    Circle x;
    x.x = 3;
    x.y = 6;
    float h = 15.0;
    float j = 16.0;
    x.Move(h, h);
    x.Move(j, j);
}