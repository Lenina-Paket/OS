#include "../include/figure.hpp"

Figure::Figure() { vector<pdd> coords; _coords = coords;}

Figure::~Figure() noexcept {}

ostream &operator<<(ostream & stream, const Figure &figure) {
    if (figure._coords.size() == 0) {
        return stream << 0;
    }

    for (size_t i = 0; i < figure._coords.size(); ++i) {
        stream << "Point " << i + 1 << "| ";
        stream << figure._coords[i].first << ' ' << figure._coords[i].second << '\n';
    }
    stream << '\n';
    return stream;
}

istream &operator>>(istream &stream, Figure &figure) {
    pdd tmp;
    stream >> tmp.first;
    stream >> tmp.second;
    figure._coords.push_back(tmp);    

    return stream;
}