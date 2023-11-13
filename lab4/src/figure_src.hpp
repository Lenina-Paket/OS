#include "../include/figure.hpp"



template <class T>
Figure<T>::~Figure() noexcept {}

/*
template <class U>
std::ostream &operator<<(std::ostream &stream, const Figure<U> &figure) {
    if (figure._coords.GetSize() == 0) {
        return stream << 0;
    }

    for (size_t i = 0; i < figure._coords.GetSize(); ++i) {
        stream << "Point " << i + 1 << "| ";
        stream << figure._coords[i].first << ' ' << figure._coords[i].second << '\n';
    }
    stream << '\n';
    return stream;
}

template <class U, class T>
std::istream &operator>>(std::istream &stream, Figure<U> &figure) {
    std::pair<T, T> tmp;
    stream >> tmp.first;
    stream >> tmp.second;
    figure._coords.Pushback(tmp);    

    return stream;
}*/