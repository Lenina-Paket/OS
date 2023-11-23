#include "./include/rectangle.hpp"
#include "./include/trapeoid.hpp"
#include "./include/romb.hpp"
#include "./include/array_figure.hpp"




int main() {
    Array_Figure Figures;

    
    /*vector<pdd> coords_trap;
    coords_trap.push_back({1, 3});
    coords_trap.push_back({2, 3});
    coords_trap.push_back({3, 0});
    coords_trap.push_back({0, 0});*/

    Trapeoid trap;
    cin >> trap;

    /*vector<pdd> coords_romb;
    coords_romb.push_back({2, 1.5});
    coords_romb.push_back({3, 0});
    coords_romb.push_back({2, -1.5});
    coords_romb.push_back({1, 0});*/

    Romb romb;
    cin >> romb;

    /*vector<pdd> coords_rect;
    coords_rect.push_back({-1, 1});
    coords_rect.push_back({1, 1});
    coords_rect.push_back({1, 0});
    coords_rect.push_back({-1, 0});*/
    

    Rectangle rect;
    cin >> rect;

    cout << "Центр прямоугольника: " << rect.Center().first << " " << rect.Center().second << endl;
    cout << "Центр трапеции: " << trap.Center().first << trap.Center().second << endl;
    cout << "Центр ромба: " << romb.Center().first << " " << romb.Center().second << endl;

    cout << "Площадь прямоугольника: " << double(rect)<< endl;
    cout << "Площадь трапеции: " << double(trap)<< endl;
    cout << "Площадь ромба: " << double(romb)<< endl;

    cout <<"Прямоугольник: \n" <<  rect << endl;
    cout << "Трапеция: \n" << trap << endl;
    cout << "Ромб: \n" << romb << endl;
return 0;
}