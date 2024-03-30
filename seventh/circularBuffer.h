#include <iostream>

template <typename T>
class CircularBuffer
{
private:
    T* _data;
    T* ptr_start;
    T* start;
    T* ptr_finish;
    T* finish;
    unsigned int buff_size, buff_capacity;

public:
    class iter : public std::iterator<std::random_access_iterator_tag, T>
    {
    private:
        T* ptr;

    public:

        explicit iter(T* start)
        {
            ptr = start;
        }
        iter(const iter& obj)
        {
            ptr = obj.ptr;
        }
        iter() {
            ptr = nullptr;
        }

        ~iter() = default;

        iter& operator++()
        {
            ptr = ptr + 1;
            return *this;
        }

        iter& operator--()
        {
            ptr = ptr - 1;
            return *this;
        }

        iter& operator+=(std::ptrdiff_t b)
        {
            ptr = ptr + b;
            return *this;
        }

        iter& operator-=(std::ptrdiff_t b)
        {
            ptr = ptr - b;
            return *this;
        }

        iter operator+(std::ptrdiff_t b)
        {
            ptr = ptr + b;
            return *this;
        }

        iter operator-(std::ptrdiff_t b)
        {
            ptr = ptr - b;
            return *this;
        }

        std::ptrdiff_t operator-(const iter& b) const
        {
            return ptr - b.ptr;
        }

        T& operator[](std::ptrdiff_t b) const
        {
            return *(ptr + b);
        }

        T& operator*() {
            return *ptr;
        }

        T* operator->() {
            return ptr;
        }

        bool operator==(const iter& other) const
        {
            return ptr == other.ptr;
        }
        bool operator!=(const iter& other) const
        {
            return ptr != other.ptr;
        }
        bool operator<(const iter& other) const
        {
            return ptr < other.ptr;
        }
        bool operator>(const iter& other) const
        {
            return ptr > other.ptr;
        }
        bool operator<=(const iter& other) const
        {
            return ptr <= other.ptr;
        }
        bool operator>=(const iter& other) const
        {
            return ptr >= other.ptr;
        }
    };

    // Accessing first and last positions

    iter begin() const {
        return iter(_data);
    }

    iter end() const {
        return iter(_data + buff_capacity);
    }

    // Constructors and destructor

    CircularBuffer() : buff_capacity(0), buff_size(0), _data(nullptr) {}

    CircularBuffer(int cap) : buff_capacity(cap), buff_size(0)
    {
        _data = new T[cap];
        ptr_start = _data;
        start = _data;
        ptr_finish = _data + cap - 1;
        finish = _data + cap - 1;
    }

    ~CircularBuffer() = default;

    // Adding element to start and end 

    void add_start_actualy(T el)
    {
        *ptr_start = el;
        ptr_start = _data + (ptr_start - _data + 1) % buff_capacity;
        ++buff_size;
    }

    void add_start(T el) {
        add_start_actualy(el);
    }

    void add_finish_actualy(T el)
    {
        *ptr_finish = el;
        ptr_finish = _data + (ptr_finish - _data - 1 + buff_capacity) % buff_capacity;
        ++buff_size;
    }

    void add_finish(T el) {
        add_finish_actualy(el);
    }

    // Deliting elements from start and end

    void delete_start()
    {
        ++start;
        --buff_size;
    }

    void delete_finish()
    {
        --finish;
        --buff_size;
    }

    // Adding and deleting by iterator

    void add_by_it(iter el, T num)
    {
        *el = num;
    }

    void delete_by_it(iter el)
    {

        while (el != finish) {
            _data[el] = _data[el + 1];

            if (el + 1 == finish) {
                break;
            }

            ++el;
        }

        --buff_size;
    }

    // Getting first and last elements

    T* get_start()
    {
        return start;
    }

    T* get_finish()
    {
        return finish;
    }


    // Accessing by index

    T get_by_ind(size_t ind)
    {
        return _data[(start - _data + ind) % buff_capacity];
    }

    // Changing capacity

    CircularBuffer change_cap(int cap) {
        CircularBuffer newBuff(cap);
        T* new_start = start;

        while (new_start != finish) {
            newBuff.add_start(*new_start);
            ++new_start;
        }

        newBuff.buff_size = buff_size;

        return newBuff;
    }

    unsigned int capacity() {
        return buff_capacity;
    }
    unsigned int size() {
        return buff_size;
    }
};
