#include "figure.hpp"

class Romb final : public Figure {
    public:
        Romb();
        Romb (const std::vector<pdd> &coords);
        Romb (const Romb &other) noexcept;
        Romb (Romb &&other) noexcept;

        virtual ~Romb() = default;

        friend istream &operator>>(istream &stream, Romb &romb);
        friend ostream &operator<<(ostream &stream, Romb &romb);
        pdd Center() const override;
        operator double() const override;
        Romb& operator=(Romb &&other);
        bool operator==(const Romb &other) const;

    private:
};