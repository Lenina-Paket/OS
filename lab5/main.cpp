#include <iostream>
#include "include/allocator.hpp"
#include <map>
#include "./include/vector.hpp"

int factorial (int n) {
    return (n <= 1) ? 1 : n * factorial(n-1);
}

int main() {
    std::map<int, int, std::less<int>, Allocator<std::pair<const int, int>>> mp;

    for (int i = 0; i < 10; i++) {
        mp[i] = factorial(i);
    }

    for (auto el: mp) {
        std::cout << el.first << ' ' << el.second << std::endl;
    }
    //добавил много-много (вообще много) добавлений и удалений
    Vector<int, Allocator<int>> vec;
    for (int i = 0; i < 5000; i++) {
    if (i % 2 == 0) {
        vec.pushBack(i);
        vec.pop_back();
        vec.pushBack(i*2);
    } else {
        vec.pop_back();
    }
    }
    
    

    for (const auto &el : vec) {
        std::cout << el << std::endl;
    }

return 0;
}