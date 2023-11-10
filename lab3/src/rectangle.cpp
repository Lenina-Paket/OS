#include "../include/rectangle.hpp"

Rectangle::Rectangle() {
    vector<pdd> coords;
    _coords = coords;
}

Rectangle::Rectangle(const std::vector<pdd> &coords) {
    if (coords.size() != 4) {
        throw std::invalid_argument("Error! Rectangle Constructor: invalid number of coordinates");
    } else if (not(IsCoordsValid_Rectangle(coords))) {
        throw std::invalid_argument("Error! Rectangle Constructor: you trying make not a Rectangle");
    } else {
        _coords = coords;
    }
}

Rectangle::Rectangle(const Rectangle &other) noexcept {
    _coords = other._coords;
}

Rectangle::Rectangle(Rectangle &&other) noexcept {
    this->_coords = move(other._coords);
}

pdd Rectangle::Center() const {
    double sum_x = 0, sum_y = 0;

    for (int i = 0; i < this->_coords.size(); i++) {
        sum_x += this->_coords[i].first;
        sum_y += this->_coords[i].second;
    }

    return {sum_x / this->_coords.size(),sum_y / this->_coords.size()};
} 

Rectangle::operator double () const {
    double area;
    area = sqrt(
        ((_coords[0].first - _coords[1].first) * (_coords[0].first - _coords[1].first)) + 
    
    ((_coords[0].second - _coords[1].second) * (_coords[0].second - _coords[1].second))
    
    ) * 

    sqrt(((_coords[1].first - _coords[2].first) * (_coords[1].first - _coords[2].first)) + 
    
    ((_coords[1].second - _coords[2].second) * (_coords[1].second - _coords[2].second)));

    return area;
}

istream &operator>>(istream &stream, Rectangle &rect) {
    pdd temp;
    for (int i = 0; i < 4; i++) {
        stream >> temp.first >> temp.second;
        rect._coords.push_back(temp);
    }
    return stream;
}

ostream &operator<<(ostream &stream, Rectangle &rect) {
    for (size_t i = 0; i < rect._coords.size(); ++i) {
        stream << "Coord " << i + 1 << " is ";
        stream << rect._coords[i].first << ' ' << rect._coords[i].second << '\n';
    }
    stream << '\n';
    return stream;

}

bool Rectangle::operator==(const Rectangle &other) const {
    for (int i = 0; i < _coords.size(); i++) {
        if (this->_coords[i] != other._coords[i]) {
            return false;
        }
    }
    return true;

}

Rectangle& Rectangle::operator=(Rectangle &&other) {
    for (int i = 0; _coords.size(); i++) {
        _coords[i] = other._coords[i];
    }
    return *this;
}

bool Rectangle::IsCoordsValid_Rectangle(const std::vector<pdd> &coords) {
    pdd AB, BC, CD, AD;
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