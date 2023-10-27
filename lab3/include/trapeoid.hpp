#include "figure.hpp"

class Trapeoid final : public Figure {
    public:
        Trapeoid();
        Trapeoid (const std::vector<pdd> &coords);
        Trapeoid (const Trapeoid &other) noexcept;
        Trapeoid (Trapeoid &&other) noexcept;

        virtual ~Trapeoid() = default;

        pdd Center() const override;
        operator double () const override;

        friend istream &operator>>(istream &stream, Trapeoid &trap);
        friend ostream &operator<<(ostream &stream, Trapeoid &trap);

        Trapeoid& operator=(Trapeoid &&other);
        bool operator==(const Trapeoid & other) const;
    private:
};