#include <iostream>
#include "funcs.h"

int main() {
    int n;
    std::cin >> n;

    Stack<std::string> a = Stack<std::string>(n);

    try{
    for(int i = 0; i < n; ++i) {
        std::string num;
        std::cin >> num;
        a.add_top(num);
    }

    a.delete_top();
    std::cout << a.get_top();

    }catch(std::invalid_argument &e){
        std::cerr << e.what() << "\n";
    }
}