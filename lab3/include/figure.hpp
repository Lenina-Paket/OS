#pragma once

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

using pdd = pair<double, double>;


class Figure {
    public:
        Figure();
        Figure(const vector<pdd> &coords);
        ~Figure() noexcept;

        friend ostream &operator<<(ostream &stream, const Figure &figure);
        friend istream &operator>>(istream &stream, Figure &figure);

        virtual pdd Center() const = 0;
        virtual operator double () const = 0;

    protected:
        vector<pdd> _coords;
};
