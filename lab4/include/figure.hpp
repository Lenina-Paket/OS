#pragma once

#include "../include/array.hpp"
#include <cmath>

template <class T>
class Figure {
    public:
        Figure();
        ~Figure() noexcept;

        virtual std::pair<T, T> Center() const = 0;
        virtual operator double () const = 0;

        template <class U>
        friend std::ostream &operator<<(std::ostream &stream, const Figure &figure) {
            if (figure._coords.GetSize() == 0) {
                return stream << 0;
            }

        for (size_t i = 0; i < figure._coords.GetSize(); ++i) {
            stream << "Point " << i + 1 << "| ";
            stream << figure._coords[i].first << ' ' << figure._coords[i].second << '\n';
        }
        stream << '\n';
        return stream;
        };

        template <class U>
        friend std::istream &operator>>(std::istream &stream, Figure &figure) {
            std::pair<T, T> tmp;
            stream >> tmp.first;
            stream >> tmp.second;
            figure._coords.Pushback(tmp);    

            return stream;
        };
    protected:
    Array<std::pair<T, T>> _coords;
};

#include "../src/figure_src.hpp"
