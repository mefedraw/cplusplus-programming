class Circle {
    private:
        float radius;
    public:
        float x;
        float y;
        void Move(float& to_x, float& to_y);
        void Move(float* to_x, float* to_y);
};

struct Complex {
    float re;
    float im;
};

// first task
void change(int &a, int &b);
void change(int *a, int *b);
// second task
int without(float &a);
int without(float *a);
//third task
void multiple(Complex *num, float a);
void multiple(Complex &num, float a);
