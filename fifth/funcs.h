#ifndef FUNCS_H
#define FUNCS_H

#define MAX_SIZE 10

template <typename T>
class Stack{
    private:
        int size;
        T *elems;
        int top;
    public:
        Stack(int size);


        void delete_top();
        void add_top(T elem);
        T get_top();
};

template <typename T>
Stack<T>::Stack(int size) {
    this->size = size;
    elems = new T[size];
    top = -1;
}

template <typename T>
void Stack<T> :: add_top(T elem) {
    ++top;
    if(top == MAX_SIZE) {
        throw std::invalid_argument("Too many elements");
    }else {
        elems[top] = elem;
    }
}

template <typename T>
void Stack<T> :: delete_top() {
    if(top == -1) {
        throw std::invalid_argument("No elements in the stack");
    }else {
        --top;
    }
}

template <typename T>
T Stack<T> :: get_top() {
    if(top == -1) {
        throw std::invalid_argument("No elements in the stack");
    }else {
        return elems[top];
    }
}

template <typename T> T maxElem(T array[], int size) {
    T maxx = array[0];
    for(int i = 0; i < size; ++i) {
        if(maxx < array[i]) maxx = array[i];
    }
    return maxx;
}

#endif