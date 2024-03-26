#include <iterator>

// I didn't run it, so if there are mistakes - pull request

template <typename T>
class CircularBuffer
{
private:
    T *_data, ptr_begin, ptr_end, begin, end;
    unsigned int buff_size, buff_capacity;

public:
    class iter : public std::iterator<std::random_access_iterator_tag, T>
    {
    private:
        T *ptr;

    public:
        iter &operator++()
        {
            ptr = (ptr + 1) % buff_capacity;
            return *this;
        }

        iter &operator--()
        {
            ptr = (ptr - 1 + buff_capacity) % buff_capacity;
            return *this;
        }

        iter &operator+=(std::ptrdiff_t b)
        {
            ptr = (ptr + b) % buff_capacity;
            return *this;
        }

        iter &operator-=(std::ptrdiff_t b)
        {
            ptr = (ptr - b + buff_capacity) % buff_capacity;
            return *this;
        }

        iter operator+(std::ptrdiff_t b) const
        {
            iter newIter = *this;
            newIter.ptr = (ptr + b) % buff_capacity;
            return newIter;
        }

        iter operator-(std::ptrdiff_t b) const
        {
            iter newIter = *this;
            newIter.ptr = (ptr - b + buff_capacity) % buff_capacity;
            return newIter;
        }

        std::ptrdiff_t operator-(const iter &b) const
        {
            return b.ptr - ptr;
        }

        T& operator[](std::ptrdiff_t b) const
        {
            return *(ptr + b);
        }

        bool operator==(const iter &other) const
        {
            return ptr == other.ptr;
        }
        bool operator!=(const iter &other) const
        {
            return ptr != other.ptr;
        }
        bool operator<(const iter &other) const
        {
            return ptr < other.ptr;
        }
        bool operator>(const iter &other) const
        {
            return ptr > other.ptr;
        }
        bool operator<=(const iter &other) const
        {
            return ptr <= other.ptr;
        }
        bool operator>=(const iter &other) const
        {
            return ptr >= other.ptr;
        }
    };

    CircularBuffer() : buff_capacity(0), buff_size(0), _data(nullptr) {}

    CircularBuffer(int cap) : buff_capacity(cap), buff_size(0)
    {
        _data = new T[buff_capacity];
        ptr_begin = begin = _data;
        ptr_end = end = _data + buff_capacity;
    }

    // Add and delete from start and end

    void add_end(T el)
    {
        *ptr_end = el;
        ptr_end = (end - 1 + buff_capacity) % buff_capacity;
        ++buff_size;
    }

    void add_start(T el)
    {
        *ptr_begin = el;
        ptr_begin = (begin + 1) % buff_capacity;
        ++buff_size;
    }

    void delete_start()
    {
        ++begin;
        --buff_size;
    }

    void delete_end()
    {
        --end;
        --buff_size;
    }

    // Adding and deleting by iterator

    void add_by_it(iter el)
    {
        *((begin + el) % buff_capacity) = *el;
    }

    void delete_by_it(iter el)
    {
        
        while(el != end) {
            _data[el] = _data[el + 1];

            if(el + 1 == end) {
                break;
            }

            ++el;
        }

        --buff_size;
    }

    // Getting first and last elements

    T get_start()
    {
        return *begin;
    }

    T get_end()
    {
        return *end;
    }

    // Accessing by index

    T get_by_ind(size_t ind)
    {
        return *((begin + ind) % buff_capacity);
    }

    // Changing capacity

    CircularBuffer change_cap(size_t cap) {
        CircularBuffer newBuff(cap);

        while(begin != end) {
            newBuff.add_start(*begin);
            ++begin;
        }

        return newBuff;
    }
};