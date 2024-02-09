#include <cmath>
#include "Triangle.h"

Triangle::Triangle(Coords side_a, Coords side_b, Coords side_c) {
    a.x = side_a.x;
    a.y = side_a.y;

    b.x = side_b.x;
    b.y = side_b.y;

    c.x = side_c.x;
    c.y = side_c.y;

    first = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); // AB
    second = sqrt((c.x - b.x) * (c.x - b.x) + (c.y - b.y) * (c.y - b.y)); // BC
    third = sqrt((c.x - a.x) * (c.x - a.x) + (c.y - a.y) * (c.y - a.y)); // AC

}
bool Triangle :: operator>(Triangle const& one) {
    float p1 = (first + second + third) / 2;
    float p2 = (one.first + one.second + one.third) / 2;

    return sqrt(p1 * (p1 - first) * (p1 - second) * (p1 - third)) > sqrt(p2 * (p2 - one.first) * (p2 - one.second) * (p2 - one.third));
}

bool Triangle :: operator==(Triangle const& one) {
    float p1 = (first + second + third) / 2;
    float p2 = (one.first + one.second + one.third) / 2;

    return sqrt(p1 * (p1 - first) * (p1 - second) * (p1 - third)) == sqrt(p2 * (p2 - one.first) * (p2 - one.second) * (p2 - one.third));
}

bool Triangle :: operator<(Triangle const& one) {
    float p1 = (first + second + third) / 2;
    float p2 = (one.first + one.second + one.third) / 2;

    return sqrt(p1 * (p1 - first) * (p1 - second) * (p1 - third)) < sqrt(p2 * (p2 - one.first) * (p2 - one.second) * (p2 - one.third));
}

bool Triangle :: operator!=(Triangle const& one) {
    float p1 = (first + second + third) / 2;
    float p2 = (one.first + one.second + one.third) / 2;

    return sqrt(p1 * (p1 - first) * (p1 - second) * (p1 - third)) != sqrt(p2 * (p2 - one.first) * (p2 - one.second) * (p2 - one.third));
}