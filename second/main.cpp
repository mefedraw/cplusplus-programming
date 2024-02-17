#include <iostream>

using namespace std;

int main() {
    Complex cmp(3, 4);
    cmp.multiple_on_number(4);
    float len = cmp.length();
    cmp.print();
}
