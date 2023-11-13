#include "include/rectangle.hpp"
#include "include/romb.hpp"
#include "include/trapeoid.hpp"
#include "include/figure.hpp"
#include "include/array.hpp"
#include <iostream>
using pdd = std::pair<int, int>;

int main() {
    Array<pdd> list{{-1, 1}, {1, 1}, {1, 0}, {-1, 0}};
    std::cout << list.GetSize() << std::endl;
    //std::initializer_list<pdd> list2{{2, 1.5}, {3, 0}, {2, -1.5}, {1, 0
    //Rectangle<int> rect(list);
    //Romb<double> romb({2, 1.5}, {3, 0}, {2, -1.5}, {1, 0});
    /*Array<Figure<double>*> array {&rect, &romb}; 
    pdd cent = romb.Center();
    std::cout << cent.first << ' ' << cent.second << std::endl;*/

return 0;
}