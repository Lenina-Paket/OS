#include "../include/trapeoid.hpp"

Trapeoid::Trapeoid() {
    vector<pdd> coords;
    _coords = coords;
}

Trapeoid::Trapeoid(const std::vector<pdd> &coords) {
    if (coords.size() != 4) {
        throw std::range_error("Error! Trapeoid Constructor: invalid number of coordinates");
    } else {
        _coords = coords;
    }
}

Trapeoid::Trapeoid(const Trapeoid &other) noexcept {
    _coords = other._coords;
}

Trapeoid::Trapeoid(Trapeoid &&other) noexcept {
    this->_coords = move(other._coords);
}

Trapeoid::operator double () const {
    double area;
    area = (
    sqrt(((_coords[0].first - _coords[1].first) * (_coords[0].first - _coords[1].first)) +
        ((_coords[0].second - _coords[1].second) * (_coords[0].second - _coords[1].second))) 
    +
    sqrt(((_coords[2].first - _coords[3].first) * (_coords[2].first - _coords[3].first)) +
        ((_coords[2].second - _coords[3].second) * (_coords[2].second - _coords[3].second)))
        ) / 2;

    double d = abs (
        sqrt(((_coords[0].first - _coords[1].first) * (_coords[0].first - _coords[1].first)) +
            ((_coords[0].second - _coords[1].second) * (_coords[0].second - _coords[1].second))) 
    -
        sqrt(((_coords[2].first - _coords[3].first) * (_coords[2].first - _coords[3].first)) +
            ((_coords[2].second - _coords[3].second) * (_coords[2].second - _coords[3].second)))
    ) / 2;

    double g = ((_coords[0].first - _coords[3].first) * (_coords[0].first - _coords[3].first)) +
        ((_coords[0].second - _coords[3].second) * (_coords[0].second - _coords[3].second));


    double h = sqrt(g - d*d);
    area *= h;
 
    return area;
}

pdd Trapeoid::Center() const {
    double sum_x = 0, sum_y = 0;

    for (int i = 0; i < this->_coords.size(); i++) {
        sum_x += this->_coords[i].first;
        sum_y += this->_coords[i].second;
    }

    return {sum_x / this->_coords.size(),sum_y / this->_coords.size()};
} 

istream &operator>>(istream &stream, Trapeoid &trap) {
    pdd temp;
    for (int i = 0; i < 4; i++) {
        stream >> temp.first >> temp.second;
        trap._coords.push_back(temp);
    }
    return stream;
}

ostream &operator<<(ostream &stream, Trapeoid &trap) {
    for (size_t i = 0; i < trap._coords.size(); ++i) {
        stream << "Coord " << i + 1 << " is ";
        stream << trap._coords[i].first << ' ' << trap._coords[i].second << '\n';
    }
    stream << '\n';
    return stream;

}

bool Trapeoid::operator==(const Trapeoid &other) const {
    for (int i = 0; i < _coords.size(); i++) {
        if (this->_coords[i] != other._coords[i]) {
            return false;
        }
    }
    return true;

}

Trapeoid& Trapeoid::operator=(Trapeoid &&other) {
    for (int i = 0; _coords.size(); i++) {
        _coords[i] = other._coords[i];
    }
    return *this;
}



