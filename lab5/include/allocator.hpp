#pragma once

#include <iostream>
#include <list>

template <typename T, size_t BLOCK_SIZE = 50000>
class Allocator {
    private:
        T* _used_blocks;
        std::list<T*> _free_blocks;
        size_t _free_count;
    public:
        using value_type = T;
        using pointer = T*;
        using const_pointer = const T*;
        using size_type = std::size_t;

        Allocator() {
            _used_blocks = new T[BLOCK_SIZE];
            _free_blocks = std::list<T*>(BLOCK_SIZE);
            int i = 0;
            for (auto& el : _free_blocks) {
                el = &_used_blocks[i];
                ++i;
            }
            _free_count = BLOCK_SIZE;
        };

        ~Allocator() noexcept {
            delete[] _used_blocks;
        }

        pointer allocate(size_t n) {
            if (n > _free_count) {
                throw std::logic_error("You're wanna to allocate too much");
            }

            T* ptr = _free_blocks.front();
            for (int i = 0; i < n; i++) {
                _free_blocks.pop_front();
            }

            _free_count -= n;

            return ptr;
        };

        void deallocate(pointer ptr, size_type n) {
            if (n > BLOCK_SIZE - _free_count) {
                throw std::logic_error("You wanna to deallocate too much");
            }
            T* temp = ptr;
            for (int i = 0; i < n; i++) {
                _free_blocks.push_back(temp);
                temp += sizeof(T);
            }
            _free_count += n;
        };

        template<class U>
        struct rebind {
            using other = Allocator<U, BLOCK_SIZE>;
        };
        size_t free_count() {
            return _free_count;
        }
};
