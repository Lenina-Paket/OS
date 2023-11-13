#pragma once

#include "figure.hpp"

template <class T>
class Romb final : public Figure<T> {
    public:
        Romb();
        Romb (const Array<std::pair<T, T>> &coords);
        Romb (const Romb<T> &other) noexcept;
        Romb (Romb<T> &&other) noexcept;

        virtual ~Romb() = default;

        bool IsCoordsValid_Romb(const Array<std::pair<T, T>> &coords);

        template <class U> friend std::istream &operator>>(std::istream &stream, Romb &romb) {
            std::pair<T, T> temp;
            for (int i = 0; i < 4; i++) {
                stream >> temp.first >> temp.second;
                romb._coords.PushBack(temp);
            }
            return stream;
        };
        template <class U> friend std::ostream &operator<<(std::ostream &stream, Romb &romb) {
            for (size_t i = 0; i < romb._coords.GetSize(); ++i) {
                stream << "Coord " << i + 1 << " is ";
                stream << romb._coords[i].first << ' ' << romb._coords[i].second << '\n';
            }
            stream << '\n';
            return stream;
        };

        std::pair<T, T> Center() const override;
        operator double() const override;
        
        Romb &operator=(Romb &&other);
        bool operator==(const Romb &other) const;   
};

#include "../src/romb_src.hpp"