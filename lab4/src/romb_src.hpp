#include "../include/romb.hpp"

template <class T>
Romb<T>::Romb() {
    Array<std::pair<T, T>> coords;
    this->_coords = coords;
}

template <class T>
Romb<T>::Romb(const Array<std::pair<T, T>> &coords) {
    if (coords.GetSize() != 4) {
        throw std::range_error("Error! Romb Constructor: invalid number of coordinates");
    } else if (not(IsCoordsValid_Romb(coords))) {
        throw std::invalid_argument("Error! Romb Constructor: you trying to make not a Romb");
    } else {
        this->_coords = coords;
    }
} 

template <class T>
Romb<T>::Romb(const Romb<T> &other) noexcept {
    this->_coords = other._coords;
}

template <class T>
Romb<T>::Romb(Romb<T> &&other) noexcept {
    this->_coords = move(other._coords);
}

template <class T>
std::pair<T, T> Romb<T>::Center() const {
    double sum_x = 0, sum_y = 0;
    for (int i = 0; i < this->_coords.GetSize(); i++) {
        sum_x += this->_coords[i].first;
        sum_y += this->_coords[i].second;
    }
    return {sum_x / this->_coords.GetSize(),sum_y / this->_coords.GetSize()};
} 

template <class T>
Romb<T>::operator double () const {
    double area, diag1, diag2;
    diag1 = 
        sqrt(
            (this->_coords[0].first - this->_coords[2].first) * (this->_coords[0].first - this->_coords[2].first) +

            (this->_coords[0].second - this->_coords[2].second) * (this->_coords[0].second - this->_coords[2].second)
        ); 
    diag2 = sqrt (
            (this->_coords[1].first - this->_coords[3].first) * (this->_coords[1].first - this->_coords[3].first) +

            (this->_coords[1].second - this->_coords[3].second) * (this->_coords[1].second - this->_coords[3].second)
        );
    area = diag1 * diag2 / 2;
    return area;
}
/*
template <class T>
std::istream &operator>>(std::istream &stream, Romb<T> &romb) {
    std::pair<T, T> temp;
    for (int i = 0; i < 4; i++) {
        stream >> temp.first >> temp.second;
        romb._coords.PushBack(temp);
    }
    return stream;
}

template <class T>
std::ostream &operator<<(std::ostream &stream, Romb<T> &romb) {
    for (size_t i = 0; i < romb._coords.GetSize(); ++i) {
        stream << "Coord " << i + 1 << " is ";
        stream << romb._coords[i].first << ' ' << romb._coords[i].second << '\n';
    }
    stream << '\n';
    return stream;

}*/

template <class T>
bool Romb<T>::operator==(const Romb<T> &other) const {
    for (int i = 0; i < this->_coords.GetSize(); i++) {
        if (this->_coords[i] != other._coords[i]) {
            return false;
        }
    }
    return true;

}

template <class T>
Romb<T> &Romb<T>::operator=(Romb<T> &&other) {
    for (int i = 0; this->_coords.GetSize(); i++) {
        this->_coords[i] = other._coords[i];
    }
    return *this;
}

template <class T>
bool Romb<T>::IsCoordsValid_Romb(const Array<std::pair<T, T>> &coords) {
    std::pair<T, T> AB, BC, CD, AD;
    AB.first = (coords[0].first - coords[1].first);
    AB.second = (coords[0].second - coords[1].second);

    BC.first = (coords[1].first - coords[2].first);
    BC.second = (coords[1].second - coords[2].second);

    CD.first = (coords[2].first - coords[3].first);
    CD.second = (coords[2].second - coords[3].second);

    AD.first = (coords[0].first - coords[3].first);
    AD.second = (coords[0].second - coords[3].second);

    return (abs((sqrt(AB.first * AB.first + AB.second * AB.second) - sqrt(CD.first * CD.first + CD.second * CD.second)) < 0.0001) and
        abs((sqrt(BC.first * BC.first + BC.second * BC.second) - sqrt(AB.first * AB.first + AB.second * AB.second)) < 0.0001) and
        (abs(sqrt(AD.first * AD.first + AD.second * AD.second) - sqrt(AB.first * AB.first + AB.second * AB.second)) < 0.0001) and

        (abs((AB.first * CD.first + AB.second * CD.second) / 
        sqrt((AB.first * AB.first + AB.second * AB.second) * (CD.first * CD.first + CD.second * CD.second))) == 1) and
        
        (abs((AD.first * BC.first + AD.second * BC.second) / 
        sqrt((AD.first * AD.first + AD.second * AD.second) * (BC.first * BC.first + BC.second * BC.second))) == 1));

}