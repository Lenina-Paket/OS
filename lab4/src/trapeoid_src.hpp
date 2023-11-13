#include "../include/trapeoid.hpp"

template <class T>
Trapeoid<T>::Trapeoid() {
    Array<std::pair<T, T>> coords;
    this->_coords = coords;
}

template <class T>
Trapeoid<T>::Trapeoid(const Array<std::pair<T, T>> &coords) {
    if (coords.GetSize() != 4) {
        throw std::invalid_argument("Error! Trapeoid Constructor: invalid number of coordinates");
    } else if (not(IsCoordsValid_Trapeoid(coords))) {
        throw std::invalid_argument("Error! Trapeoid Constructor: you trying to make not a Trapeoid");
    } else {
        this->_coords = coords;
    }
}

template <class T>
Trapeoid<T>::Trapeoid(const Trapeoid<T> &other) noexcept {
    this->_coords = other._coords;
}

template <class T>
Trapeoid<T>::Trapeoid(Trapeoid<T> &&other) noexcept {
    this->_coords = move(other._coords);
}

template <class T>
Trapeoid<T>::operator double () const {
    double area;
    area = (
    sqrt(((this->_coords[0].first - this->_coords[1].first) * (this->_coords[0].first - this->_coords[1].first)) +
        ((this->_coords[0].second - this->_coords[1].second) * (this->_coords[0].second - this->_coords[1].second))) 
    +
    sqrt(((this->_coords[2].first - this->_coords[3].first) * (this->_coords[2].first - this->_coords[3].first)) +
        ((this->_coords[2].second - this->_coords[3].second) * (this->_coords[2].second - this->_coords[3].second)))
        ) / 2;

    double d = abs (
        sqrt(((this->_coords[0].first - this->_coords[1].first) * (this->_coords[0].first - this->_coords[1].first)) +
            ((this->_coords[0].second - this->_coords[1].second) * (this->_coords[0].second -this-> _coords[1].second))) 
    -
        sqrt(((this->_coords[2].first - this->_coords[3].first) * (this->_coords[2].first - this->_coords[3].first)) +
            ((this->_coords[2].second - this->_coords[3].second) * (this->_coords[2].second - this->_coords[3].second)))
    ) / 2;

    double g = ((this->_coords[0].first - this->_coords[3].first) * (this->_coords[0].first - this->_coords[3].first)) +
        ((this->_coords[0].second - this->_coords[3].second) * (this->_coords[0].second - this->_coords[3].second));


    double h = sqrt(g - d*d);
    area *= h;
 
    return area;
}

template <class T>
std::pair<T, T> Trapeoid<T>::Center() const {
    double sum_x = 0, sum_y = 0;

    for (int i = 0; i < this->_coords.GetSize(); i++) {
        sum_x += this->_coords[i].first;
        sum_y += this->_coords[i].second;
    }

    return {sum_x / this->_coords.GetSize(),sum_y / this->_coords.GetSize()};
} 
/*
template <class T>
std::istream &operator>>(std::istream &stream, Trapeoid<T> &trap) {
    std::pair<T, T> temp;
    for (int i = 0; i < 4; i++) {
        stream >> temp.first >> temp.second;
        trap._coords.PushBack(temp);
    }
    return stream;
}

template <class T>
std::ostream &operator<<(std::ostream &stream, Trapeoid<T> &trap) {
    for (size_t i = 0; i < trap._coords.GetSize(); ++i) {
        stream << "Coord " << i + 1 << " is ";
        stream << trap._coords[i].first << ' ' << trap._coords[i].second << '\n';
    }
    stream << '\n';
    return stream;

}
*/

template <class T>
bool Trapeoid<T>::operator==(const Trapeoid<T> &other) const {
    for (int i = 0; i < this->_coords.GetSize(); i++) {
        if (this->_coords[i] != other._coords[i]) {
            return false;
        }
    }
    return true;

}

template <class T>
Trapeoid<T> &Trapeoid<T>::operator=(Trapeoid<T> &&other) {
    for (int i = 0; this->_coords.GetSize(); i++) {
       this->_coords[i] = other._coords[i];
    }
    return *this;
}

template <class T>
bool Trapeoid<T>::IsCoordsValid_Trapeoid(const Array<std::pair<T, T>> &coords) {
    std::pair<T, T> AB, BC, CD, AD;
    AB.first = (coords[0].first - coords[1].first);
    AB.second = (coords[0].second - coords[1].second);

    BC.first = (coords[2].first - coords[1].first);
    BC.second = (coords[2].second - coords[1].second);

    CD.first = (coords[2].first - coords[3].first);
    CD.second = (coords[2].second - coords[3].second);

    AD.first = (coords[0].first - coords[3].first);
    AD.second = (coords[0].second - coords[3].second);

    return ((abs((AB.first * CD.first + AB.second * CD.second) / 
        sqrt((AB.first * AB.first + AB.second * AB.second) * (CD.first * CD.first + CD.second * CD.second))) == 1) and
        
        abs((AD.first * BC.first + AD.second * BC.second) / 
        sqrt((AD.first * AD.first + AD.second * AD.second) * (BC.first * BC.first + BC.second * BC.second))) != 1);
}