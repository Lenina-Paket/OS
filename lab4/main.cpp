#include "src/rectangle.hpp"
#include "src/romb.hpp"
#include "src/trapeoid.hpp"
#include "src/figure.hpp"
#include "src/array.hpp"
#include <iostream>


int main() {
    Array<Figure<double>*> Figures;

    std::cout << "Enter a romb coords" << std::endl;
    Romb<double> romb;
    std::cin >> romb;
    
    std::cout << "Enter a rect coords" << std::endl;
    Rectangle<double> rect;
    std::cin >> rect;

    std::cout << "Enter a trap coords" << std::endl;
    Trapeoid<double> trap;
    std::cin >> trap;
    
    

    std::cout << "Центр прямоугольника: " << rect.Center().first << " " << rect.Center().second << std::endl;
    std::cout << "Центр трапеции: " << trap.Center().first << trap.Center().second << std::endl;
    std::cout << "Центр ромба: " << romb.Center().first << " " << romb.Center().second << std::endl;

    std::cout << "Площадь прямоугольника: " << double(rect)<< std::endl;
    std::cout << "Площадь трапеции: " << double(trap)<< std::endl;
    std::cout << "Площадь ромба: " << double(romb)<< std::endl;

    std::cout <<"Прямоугольник: \n" <<  rect << std::endl;
    std::cout << "Трапеция: \n" << trap << std::endl;
    std::cout << "Ромб: \n" << romb << std::endl;
return 0;
}