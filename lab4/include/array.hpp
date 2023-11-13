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
        ~Array();

        void Pushback(T &obj);
        void DeleteToIndex(size_t index);
        size_t GetSize() const;
        T &operator[](size_t index) const;
        void operator=(const Array &other);
    private:
        size_t _size;
        std::shared_ptr<T[]> _array;
};

#include "../src/array_src.hpp"