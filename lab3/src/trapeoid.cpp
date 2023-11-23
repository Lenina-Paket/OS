#include "../include/trapeoid.hpp"

Trapeoid::Trapeoid() {
    vector<pdd> coords;
    _coords = coords;
}

Trapeoid::Trapeoid(const std::vector<pdd> &coords) {
    if (coords.size() != 4) {
        throw std::invalid_argument("Error! Trapeoid Constructor: invalid number of coordinates");
    } else if (not(IsCoordsValid_Trapeoid(coords))) {
        throw std::invalid_argument("Error! Trapeoid Constructor: you trying to make not a Trapeoid");
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


bool Trapeoid::IsCoordsValid_Trapeoid(const std::vector<pdd> &coords) {
    pdd AB, BC, CD, AD;
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