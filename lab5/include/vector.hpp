#pragma once

#include <iostream>
#include <memory>


template <class T, class Allocator = std::allocator<T>>
class Vector {
    private:
        Allocator _alloc;
        T* _data;
        size_t _size, _capacity;
    
    public:
        using value_type = T;
        Vector() {
            _data = nullptr;
            _size = 0;
            _capacity = 0;
        }

        Vector(size_t n) {
            _size = n;
            _capacity = n;
            _data = _alloc.allocate(n);
        }

        Vector(const std::initializer_list<T> &list) {
            _size = list.size();
            _data = _alloc.allocate(_size);
            _capacity = _size;
        };

        Vector(const Vector &other) {
            _size = other._size;
            _capacity = other._capacity;
            _data = _alloc.allocate(other._size);
            for (size_t i = 0; i < _size; i++) {
                _data[i] = other._data[i];
            }
        }

        Vector(const Vector &&other) {
            _size = std::move(other._size);
            _capacity = std::move(other._capacity);
            _data = std::move(other._data);
        };

        T& operator[] (size_t ind) {
            return _data[ind];
        }

        void reserve(size_t n) {
            if (n > _capacity) {
                size_t oldCapacity = _capacity;
                _capacity = n;
                T* oldData = _data;
                _data = _alloc.allocate(_capacity);
                for (size_t i = 0; i < _capacity; i++) {
                    new (&_data[i]) T();
                }
                for (size_t i = 0; i < size(); i++) {
                    _data[i] = oldData[i];
                }
            }
        }

        void resize(size_t n) {
            if (n > _capacity) {
                size_t newCapacity = (_capacity == 0 ? 1 : _capacity);
                while (n > newCapacity) {
                    newCapacity *= 2;
                }
                reserve(newCapacity);
            }
            _size = n;
        }

        void pushBack(const T &a) {
            resize(size() + 1);
            _data[size() - 1] = a;
        }
        
        void pop_back() {
            if (_size == 0) {
                throw std::logic_error("pop_back: Vector is empty!");
            }
            _size--;
        };

        void clear() {
            _alloc.deallocate(_data, _size); // добавил деаллоцирование 
            _data = nullptr;
            _size = 0;
        };
        

        size_t size() {
            return _size;
        };

        bool empty() {
            return _size == 0;
        }

        friend std::ostream& operator<<(std::ostream &stream, const Vector &vector) {
            for (size_t i = 0; i < vector.size(); i++) {
                stream << vector.data[i] << " ";
            }
            return stream;
        }

        public: 
        class Iterator {
            private:
                Vector<T, Allocator>& vector;
                size_t ind;
            public:
                using difference_type = int;
                using value_type = typename Vector<T, Allocator>::value_type;
                using reference = typename Vector<T, Allocator>::value_type&;
                using pointer = typename Vector<T, Allocator>::value_type*;
                using iterator_category = std::forward_iterator_tag;

                Iterator(Vector &v, size_t i) : vector(v), ind(i) { }
                
                //добавил throws для операторов итераторов
                Iterator& operator++() {
                    if (this->ind == this->vector.size()) throw std::logic_error("You cant use ++");
                    ++ind;
                    return *this;
                }

                Iterator& operator--() {
                    if (this->ind == 0) throw std::logic_error("You cant use --");
                    --ind;
                    return *this;
                }

                reference operator*() {
                    if (this->ind >= this->vector.size()) throw std::logic_error("Index is out o range");
                    return vector[ind];
                }

                pointer operator->() {
                    if (this->ind >= this->vector.size()) throw std::logic_error("Index is out o range");
                    return &vector[ind];
                }

                bool operator!=(const Iterator& other) const {
                    if (ind != other.ind) return true;
                    if (&vector != &(other.vector)) return true;
                    return false;
                }

                bool operator==(const Iterator& other) const {
                    if (ind != other.ind) return false;
                    if (&vector != &(other.vector)) return false;
                    return true;
                }
            };

        class ConstIterator {
            private:
                Vector<T, Allocator>& vector;
                size_t ind;
            public:
                using difference_type = int ;
                using value_type = typename Vector<T, Allocator>::value_type;
                using reference = const typename Vector<T, Allocator>::value_type& ;
                using pointer = const typename Vector<T, Allocator>::value_type*;
                using iterator_category = std::forward_iterator_tag;

                ConstIterator(Vector &v, size_t i) : vector(v), ind(i) { }

                const ConstIterator& operator++() {
                    if (this->ind == this->vector.size()) throw std::logic_error("You cant use ++");
                    ++ind;
                    return *this;
                }

                const ConstIterator& operator--() {
                    if (this->ind == 0) throw std::logic_error("You cant use --");
                    --ind;
                    return *this;
                }

                const reference operator*() {
                    if (this->ind >= this->vector.size()) throw std::logic_error("Index is out o range");
                    return vector[ind];
                }

                const pointer operator->() {
                    if (this->ind >= this->vector.size()) throw std::logic_error("Index is out o range");
                    return &vector[ind];
                }

                bool operator!=(const ConstIterator& other) const {
                    if (ind != other.ind) return true;
                    if (&vector != &(other.vector)) return true;
                    return false;
                }

                bool operator==(const ConstIterator& other) const {
                    if (ind != other.ind) return false;
                    if (&vector != &(other.vector)) return false;
                    return true;
                }
            };
        Iterator begin() {
            return Iterator(*this, 0);
        }

        Iterator end() {
            return Iterator(*this, _size);
        }

        ConstIterator cbegin() {
            return ConstIterator(*this, 0);
        }

        ConstIterator cend() {
            return ConstIterator(*this, _size);
        }
        

};
