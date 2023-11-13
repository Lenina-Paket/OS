#include "../include/rectangle.hpp"

template <class T>
Rectangle<T>::Rectangle() {
    Array<std::pair<T, T>> coords;
    this->_coords = coords;
    
}

template <class T>
Rectangle<T>::Rectangle(const Array<std::pair<T, T>> &coords) {
    if (coords.GetSize() != 4) {
        throw std::invalid_argument("Error! Rectangle Constructor: invalid number of coordinates");
    } else if (not(IsCoordsValid_Rectangle(coords))) {
        throw std::invalid_argument("Error! Rectangle Constructor: you trying make not a Rectangle");
    } else {
        this->_coords = coords;
    }
}

template <class T>
Rectangle<T>::Rectangle(const Rectangle<T> &other) noexcept {
    this->_coords = other._coords;
}

template <class T>
Rectangle<T>::Rectangle(Rectangle<T> &&other) noexcept {
    this->_coords = move(other._coords);
}

template <class T>
std::pair<T, T> Rectangle<T>::Center() const {
    double sum_x = 0, sum_y = 0;
    for (int i = 0; i < this->_coords.GetSize(); i++) {
        sum_x += this->_coords[i].first;
        sum_y += this->_coords[i].second;
    }

    return {sum_x / this->_coords.GetSize(), sum_y / this->_coords.GetSize()};
} 

template <class T>
Rectangle<T>::operator double () const {
    double area;
    area = sqrt(
        ((this->_coords[0].first - this->_coords[1].first) * (this->_coords[0].first - this->_coords[1].first)) + 
    
    ((this->_coords[0].second - this->_coords[1].second) * (this->_coords[0].second - this->_coords[1].second))
    
    ) * 

    sqrt(((this->_coords[1].first - this->_coords[2].first) * (this->_coords[1].first - this->_coords[2].first)) + 
    
    ((this->_coords[1].second - this->_coords[2].second) * (this->_coords[1].second - this->_coords[2].second)));

    return area;
}
/*
template <class T>
std::istream &operator>>(std::istream &stream, Rectangle<T> &rect) {
    std::pair<T, T> temp;
    for (int i = 0; i < 4; i++) {
        stream >> temp.first >> temp.second;
        rect._coords.PushBack(temp);
    }
    return stream;
}

template <class T>
std::ostream &operator<<(std::ostream &stream, Rectangle<T> &rect) {
    for (size_t i = 0; i < rect._coords.GetSize(); ++i) {
        stream << "Coord " << i + 1 << " is ";
        stream << rect._coords[i].first << ' ' << rect._coords[i].second << '\n';
    }
    return stream;

}
*/

template <class T>
bool Rectangle<T>::operator==(const Rectangle<T> &other) const {
    for (int i = 0; i < this->_coords.GetSize(); i++) {
        if (this->_coords[i] != other._coords[i]) {
            return false;
        }
    }
    return true;

}

template <class T>
Rectangle<T> &Rectangle<T>::operator=(Rectangle<T> &&other) {
    for (int i = 0; this->_coords.GetSize(); i++) {
        this->_coords[i] = other._coords[i];
    }
    return *this;
}

template <class T>
bool Rectangle<T>::IsCoordsValid_Rectangle(const Array<std::pair<T, T>> &coords) {
    std::pair<T, T> AB, BC, CD, AD;
    AB.first = (coords[0].first - coords[1].first);
    AB.second = (coords[0].second - coords[1].second);

    BC.first = (coords[1].first - coords[2].first);
    BC.second = (coords[1].second - coords[2].second);

    CD.first = (coords[2].first - coords[3].first);
    CD.second = (coords[2].second - coords[3].second);

    AD.first = (coords[0].first - coords[3].first);
    AD.second = (coords[0].second - coords[3].second);

    return( (AB.first * BC.first + AB.second * BC.second == 0) and (CD.first * BC.first + CD.second * BC.second == 0) and
        (abs(sqrt(AB.first * AB.first + AB.second * AB.second) - sqrt(CD.first * CD.first + CD.second * CD.second)) < 0.0001) and
        (abs(sqrt(BC.first * BC.first + BC.second * BC.second) - sqrt(AD.first * AD.first + AD.second * AD.second)) < 0.0001) and
        (abs(sqrt(BC.first * BC.first + BC.second * BC.second) != sqrt(AB.first * AB.first + AB.second * AB.second))));
}
