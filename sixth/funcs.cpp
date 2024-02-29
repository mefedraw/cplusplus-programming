#include "funcs.h"

// for CPoint

CPoint::CPoint(float set_x, float set_y) {
    x = set_x;
    y = set_y;
}

template<typename T, typename func_T>
bool CPoint::all_of(T first, T second, bool (*func)(func_T)) {
    while(first != std::next(second)) {
        if(!(*func(first->x) || *funcs(second->x)) && !(*func(first->y) || *funcs(second->y))) {
            return false;
        }
        first = std::next(first);
    }
    return true;
}

template<typename T, typename object>
bool CPoint::is_sorted(const T& first, const T& second, bool (&func)(object, object)) {
    while(*first != *second) {
        if(!(*func(first->x, (std::next(first))->x))) {
            return false;
        }
        first = std::next(first);
    }
    return true;
}

template<typename T>
bool CPoint::is_palindrome(T first, T second) {
    for(auto left = first, right = second; left != right; left = std::next(left), right = std::prev(right)) {
        if(*left->x != *right->x || *left->y != *right->y) {
            return false;
        }
    }

    return true;
}

// for CRational

CRational::CRational(float set_x, float set_y) {
    integer = set_x;
    fract = set_y;
}

template<typename T, typename func_T>
bool CRational::all_of(T first, T second, bool (*func)(func_T)) {
    while(first != std::next(second)) {
        if(!(*func(first->integer + first->fract))) {
            return false;
        }
        first = std::next(first);
    }
    return true;
}

template<typename T, typename object>
bool CRational::is_sorted(const T& first, const T& second, bool (&func)(object, object)) {
    while(*first != *second) {
        if(!(*func(first->integer + first->fract, (std::next(first))->integer + (std::next(first))->fract))) {
            return false;
        }
        first = std::next(first);
    }
    return true;
}

template<typename T>
bool CRational::is_palindrome(T first, T second) {
    for(auto left = first, right = second; left != right; left = std::next(left), right = std::prev(right)) {
        if(*left->integer + *left->fract != *right->integer + *right->fract) {
            return false;
        }
    }

    return true;
}

// for non user data types

template<typename T, typename func_T>
bool all_of(T first, T second, bool (*func)(func_T)) {
    while(first != std::next(second)) {
        if(!(*func(first))) {
            return false;
        }
        first = std::next(first);
    }
    return true;
}

template<typename T, typename funcs_T>
bool is_sorted(T& first, T& second, bool (&func)(funcs_T, funcs_T)) {
    while(*first != *second) {
        if(!(*func(first, std::next(first)))) {
            return false;
        }
        first = std::next(first);
    }
    return true;
}

template<typename T>
bool is_palindrome(T first, T second) {
    for(auto left = first, right = second; left != right; left = std::next(left), right = std::prev(right)) {
        if(*left != *right) {
            return false;
        }
    }

    return true;
}