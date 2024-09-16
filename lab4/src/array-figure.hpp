#include "array.hpp"
#include "figure.hpp"

template <class T>
double GetAllArea(const Array<Figure<T>*> &array) {
    double sum = 0;
    for (int i = 0;i < array.GetSize(); i++) {
        sum += double(*array[i]);
    }
    return sum;
}