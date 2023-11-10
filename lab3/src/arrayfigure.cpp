#include "../include/array_figure.hpp"

Array_Figure::Array_Figure() : _size{0}, _capacity{100} {
    _array = new Figure *[_capacity];
}

Array_Figure::~Array_Figure() {
    delete[] _array;
}

void Array_Figure::Pushback(Figure *figure) {
    this->_array[_size++] = figure;
}

void Array_Figure::DeleteToIndex(size_t index) {
    if (index < 0 || index >= _size) {
        throw std::range_error("Error! Array_Figure deleteToIndex: Invalid index for deletion.");
    }
    _array[index] = _array[_size - 1];
    _size--;
}

pdd Array_Figure::GetFigureCenter(size_t index) {
    if (index <= _size and index >= 0) {
        return _array[index]->Center();
    } else throw logic_error("Incorrect index");
}

double Array_Figure::GetIndexArea(size_t index) {
    if (index <= _size and index >= 0) {
        return double(*_array[index]);
    } else throw logic_error("Incorrect index");
}

double Array_Figure::GetAllArea() {
    double sum = 0;

    for (int i = 0; i < _size; i++) {
        sum += double(*_array[i]);
    }

    return sum;
}

ostream &operator<<(ostream &stream, const Array_Figure &array_fig) {
    for (size_t i = 0; i < array_fig._size; ++i) {
        stream << *array_fig._array[i];
    }

    return stream;
}

size_t Array_Figure::GetSize() const {
    return this->_size;
}
