#include "../include/romb.hpp"

Romb::Romb() {
    vector<pdd> coords;
    _coords = coords;
}

Romb::Romb(const std::vector<pdd> &coords) {
    if (coords.size() != 4) {
        throw std::range_error("Error! Romb Constructor: invalid number of coordinates");
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