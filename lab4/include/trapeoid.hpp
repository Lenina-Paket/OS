#pragma once

#include "figure.hpp"

template <class T>
class Trapeoid final : public Figure<T> {
    public:
        Trapeoid();
        Trapeoid (const Array<std::pair<T, T>> &coords);
        Trapeoid (const Trapeoid<T> &other) noexcept;
        Trapeoid (Trapeoid<T> &&other) noexcept;

        virtual ~Trapeoid() = default;

        bool IsCoordsValid_Trapeoid(const Array<std::pair<T, T>> &coords);

        template <class U> friend std::istream &operator>>(std::istream &stream, Trapeoid &trap) {
            std::pair<T, T> temp;
            for (int i = 0; i < 4; i++) {
                stream >> temp.first >> temp.second;
                trap._coords.PushBack(temp);
            }
            return stream;
        };
        template <class U> friend std::ostream &operator<<(std::ostream &stream, Trapeoid &trap) {
            for (size_t i = 0; i < trap._coords.GetSize(); ++i) {
                stream << "Coord " << i + 1 << " is ";
                stream << trap._coords[i].first << ' ' << trap._coords[i].second << '\n';
            }
            stream << '\n';
            return stream;
        };

        std::pair<T, T> Center() const override;
        operator double () const override;

        Trapeoid &operator=(Trapeoid &&other);
        bool operator==(const Trapeoid &other) const;
};

#include "../src/trapeoid_src.hpp"