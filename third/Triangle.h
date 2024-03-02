#ifndef triangle_h
#define triangle_h

struct Coords {
    float x;
    float y;
};

class Triangle { 
    private:
        Coords a;
        Coords b;
        Coords c;
    public:
        float first;
        float second;
        float third;
        
        Triangle(Coords side_a, Coords side_b, Coords side_c);

        bool operator>(Triangle& one);
        bool operator==(Triangle& one);
        bool operator<(Triangle& one);
        bool operator!=(Triangle& one);

};

#endif
