#include "figure.hpp"

class Rectangle final : public Figure {
    public:
        Rectangle();
        Rectangle (const std::vector<pdd> &coords);
        Rectangle (const Rectangle &other) noexcept;
        Rectangle (Rectangle &&other) noexcept;

        virtual ~Rectangle() = default;

        bool IsCoordsValid_Rectangle(const std::vector<pdd> &coords);

        friend istream &operator>>(istream &stream, Rectangle &rect);
        friend ostream &operator<<(ostream &stream, Rectangle &rect);

        pdd Center() const override;
        operator double () const override;
        
        Rectangle& operator=(Rectangle &&other);
        bool operator==(const Rectangle &other) const;
};