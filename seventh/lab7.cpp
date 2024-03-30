#include "circularBuffer.h"

int main()
{
    CircularBuffer<int> b(5);
    CircularBuffer<int>::iter n;
    CircularBuffer<int>::iter m;
    CircularBuffer<int>::iter q;



    //std::cout << b.capacity() << "\n";

    CircularBuffer<int> v = b.change_cap(7);
    //std::cout << b.capacity() << "\n";

    b.add_start(3);
    b.add_start(9);
    b.add_start(90);
    b.add_finish(8);

    //b.delete_start();

    std::cout << *b.get_start() << "\n";
    std::cout << *b.get_finish() << "\n";
    std::cout << b.get_by_ind(1) << "\n";
    //std::cout << b.size() << "\n";

    
    for (n = b.begin(); n != b.end(); ++n) {
        std::cout << *n << " ";
    }

    std::cout << "\n";

    //m = ++b.begin();
    //q = b.begin();

    //std::cout << q - m;
    //std::cout << (m > q);


    m = b.begin() + 1;
    std::cout << *m;

}
