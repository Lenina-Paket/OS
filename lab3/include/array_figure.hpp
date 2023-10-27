#pragma once

#include "figure.hpp"

class Array_Figure {
    public:
        Array_Figure();
        ~Array_Figure();

        void Pushback(Figure *figure);
        void DeleteToIndex(size_t index);

        pdd GetFigureCenter(size_t index);
        double GetIndexArea(size_t index);
        double GetAllArea();
        size_t GetSize() const;
        friend ostream &operator<<(std::ostream &stream, const Array_Figure &array_fig);

    private:
        size_t _size;
        size_t _capacity;
        Figure **_array;
};