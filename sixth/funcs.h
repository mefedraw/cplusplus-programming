#ifndef FUNCS_H
#define FUNCS_H

class CPoint {
    private:
        float x;
        float y;
    public:
        CPoint(float set_x, float set_y);

        template<typename T, typename func_T>
        bool all_of(T first, T second, bool (*func)(func_T));

        template<typename T, typename object>
        bool is_sorted(const T& first, const T& second, bool (&func)(object, object));

        template<typename T>
        bool is_palindrome(T first, T second);

};

class CRational {
    private:
        float integer;
        float fract;
    public:
        CRational(float set_x, float set_y);

        template<typename T, typename func_T>
        bool all_of(T first, T second, bool (*func)(func_T));

        template<typename T, typename object>
        bool is_sorted(const T& first, const T& second, bool (&func)(object, object));

        template<typename T>
        bool is_palindrome(T first, T second);

};

template<typename T, typename func_T>
bool all_of(T first, T second, bool (*func)(func_T));

template<typename T, typename object>
bool is_sorted(const T& first, const T& second, bool (&func)(object, object));

template<typename T>
bool is_palindrome(T first, T second);

#endif