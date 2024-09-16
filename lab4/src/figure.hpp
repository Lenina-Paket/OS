#pragma once

#include "array.hpp"
#include <cmath>

template <class T>
class Figure {
    public:
        Figure() = default;
        ~Figure() = default;

        virtual std::pair<T, T> Center() const = 0;
        virtual operator double () const = 0;

    protected:
    Array<std::pair<T, T>> _coords;
};