#ifndef complex_h
#define complex_h

class Complex {
    private:
        float im;
        float re;
    public:
        Complex(Complex const& num);
        Complex(float im, float re);
        Complex(float im);
        Complex(float re);
        Complex();

        void multiple_on_number(float num);
        float length();
        void print();

        Complex operator*(Complex const& another);
        Complex operator+(Complex const& another);

};

#endif