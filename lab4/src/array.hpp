#pragma once
#include <initializer_list>
#include <algorithm>
#include <iostream>
#include <memory>

template <class T>
class Array {
    public:
        Array();
        Array(const std::initializer_list<T> &list);
        Array(const Array &other);
        Array(Array &&other) noexcept;
        ~Array() = default;

        void DeleteToIndex(size_t index);
        void Pushback(const T& element);

        size_t GetSize() const;
        T GetArray() const;

        T &operator[](size_t index) const;
        void operator=(const Array &other);
    private:
        size_t _size;
        std::shared_ptr<T[]> _array;
};

template <class T>
Array<T>::Array() {
    _size = 0;
}


template <class T>
Array<T>::Array(const std::initializer_list<T> &list) {
    this->_array = std::make_shared<T[]>(list.size());
    int i = 0;
    this->_size = list.size();
    for (T elem : list) _array[i++] = elem;
    
}

template <class T>
Array<T>::Array(const Array &other) {
    _size = other._size;
    _array = std::make_shared<T[]>(new T[_size]);
    for (int i = 0; i < _size; ++i) _array[i] = other._array[i];
}

template <class T>
Array<T>::Array(Array &&other) noexcept {
    _size = other._size;
    _array = other._array;

    other._size = 0;
    other._array = nullptr;
}

template <class T>
void Array<T>::Pushback(const T& element) { 
    this->_array[_size++] = element;
}

template <class T>
void Array<T>::DeleteToIndex(size_t index) {
    if (index < 0 or index >= _size) {
        throw std::invalid_argument("Error! Array deleteToIndex: Invalid index for deletion.");
    }
    _array[index] = _array[_size - 1];
    _size--;
}

template <class T>
size_t Array<T>::GetSize() const {
    return this->_size;
}

template <class T>
T Array<T>::GetArray() const {
    return this->_array;
}

template <class T>
T &Array<T>::operator[](size_t index) const {
    if (index >= _size) {
        throw std::range_error("Error! Array operator[]: Invalid index");
    }
    return _array[index];
}

template <class T>
void Array<T>::operator=(const Array &other) {
    this->_array = std::make_shared<T[]>(other._size);
    for (size_t i = 0; i < other.GetSize(); i++) {
        _array[i] = other._array[i];
    }
    this->_size = other._size; 
}