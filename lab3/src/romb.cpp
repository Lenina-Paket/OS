#include "../include/romb.hpp"

Romb::Romb() {
    vector<pdd> coords;
    _coords = coords;
}

Romb::Romb(const std::vector<pdd> &coords) {
    if (coords.size() != 4) {
        throw std::range_error("Error! Romb Constructor: invalid number of coordinates");
    } else if (not(IsCoordsValid_Romb(coords))) {
        throw std::invalid_argument("Error! Romb Constructor: you trying to make not a Romb");
    } else {
        _coords = coords;
    }
} 

Romb::Romb(const Romb &other) noexcept {
    _coords = other._coords;
}

Romb::Romb(Romb &&other) noexcept {
    this->_coords = move(other._coords);
}

pdd Romb::Center() const {
    double sum_x = 0, sum_y = 0;

    for (int i = 0; i < this->_coords.size(); i++) {
        sum_x += this->_coords[i].first;
        sum_y += this->_coords[i].second;
    }

    return {sum_x / this->_coords.size(),sum_y / this->_coords.size()};
} 

Romb::operator double () const {
    double area, diag1, diag2;
    diag1 = 
        sqrt(
            (_coords[0].first - _coords[2].first) * (_coords[0].first - _coords[2].first) +

            (_coords[0].second - _coords[2].second) * (_coords[0].second - _coords[2].second)
        ); 
    diag2 = sqrt (
            (_coords[1].first - _coords[3].first) * (_coords[1].first - _coords[3].first) +

            (_coords[1].second - _coords[3].second) * (_coords[1].second - _coords[3].second)
        );
    area = diag1 * diag2 / 2;
    return area;
}

istream &operator>>(istream &stream, Romb &romb) {
    pdd temp;
    for (int i = 0; i < 4; i++) {
        stream >> temp.first >> temp.second;
        romb._coords.push_back(temp);
    }
    return stream;
}

ostream &operator<<(ostream &stream, Romb &romb) {
    for (size_t i = 0; i < romb._coords.size(); ++i) {
        stream << "Coord " << i + 1 << " is ";
        stream << romb._coords[i].first << ' ' << romb._coords[i].second << '\n';
    }
    stream << '\n';
    return stream;

}

bool Romb::operator==(const Romb &other) const {
    for (int i = 0; i < _coords.size(); i++) {
        if (this->_coords[i] != other._coords[i]) {
            return false;
        }
    }
    return true;

}

Romb& Romb::operator=(Romb &&other) {
    for (int i = 0; _coords.size(); i++) {
        _coords[i] = other._coords[i];
    }
    return *this;
}

bool Romb::IsCoordsValid_Romb(const std::vector<pdd> &coords) {
    pdd AB, BC, CD, AD;
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