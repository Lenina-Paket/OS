#pragma once

#include "figure.hpp"

template <class T>
class Rectangle final : public Figure<T> {
    public:
        Rectangle();
        Rectangle (const Array<std::pair<T, T>> &coords);
        Rectangle (const Rectangle<T> &other) noexcept;
        Rectangle (Rectangle<T> &&other) noexcept;

        virtual ~Rectangle() = default;

        bool IsCoordsValid_Rectangle(const Array<std::pair<T, T>> &coords);

        template <class U> friend std::istream &operator>>(std::istream &stream, Rectangle &rect) {
            std::pair<T, T> temp;
            for (int i = 0; i < 4; i++) {
                stream >> temp.first >> temp.second;
                rect._coords.PushBack(temp);
            }
            return stream;
        };
        template <class U> friend std::ostream &operator<< (std::ostream &stream, Rectangle &rect) {
            for (size_t i = 0; i < rect._coords.GetSize(); ++i) {
                stream << "Coord " << i + 1 << " is ";
                stream << rect._coords[i].first << ' ' << rect._coords[i].second << '\n';
            }
            return stream;
        };

        std::pair<T, T> Center() const;
        operator double () const;
        
        Rectangle &operator=(Rectangle &&other);
        bool operator==(const Rectangle &other) const;

};

#include "../src/rectangle_src.hpp"
