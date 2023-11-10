#include <gtest/gtest.h>
#include "../include/trapeoid.hpp"
#include "../include/romb.hpp"
#include "../include/rectangle.hpp"
#include "../include/array_figure.hpp"
#include "../include/figure.hpp"

//-------------Rectangle tests------------------------------//

TEST(test_01, Rectangle_Constructor) {
    vector<pdd> coords;
    coords.push_back({-1, 1});
    coords.push_back({1, 1});
    coords.push_back({1, 0});
    coords.push_back({-1, 0});

    Rectangle rect(coords);
    Rectangle rect1(coords);
    Rectangle rect4(rect);
    Rectangle rect5(rect);
    Rectangle rect0(move(rect));
    ASSERT_TRUE(rect == rect1 and rect4 == rect5 and rect0 == rect4);
}

TEST(test_02, Rectangle_Constructor) {
    vector<pdd> coords;
    coords.push_back({-1, 1});
    coords.push_back({0, 1});
    coords.push_back({0, 0});
    coords.push_back({-1, 0});

    ASSERT_ANY_THROW(Rectangle rect(coords));
}

TEST(test_03, Rectangle_Constructor) {
    vector<pdd> coords;
    coords.push_back({1, 3});
    coords.push_back({2, 3});
    coords.push_back({3, 0});
    coords.push_back({0, 0});

    ASSERT_ANY_THROW(Rectangle rect(coords));
}


TEST(test_01, Rectangle_methods) {
    vector<pdd> coords;
    coords.push_back({-1, 1});
    coords.push_back({1, 1});
    coords.push_back({1, 0});
    coords.push_back({-1, 0});

    Rectangle rect(coords);
    pdd cent = {0, 0.5};
    ASSERT_TRUE(rect.Center() == cent);
}

TEST(test_02, Rectangle_methods) {
    vector<pdd> coords;
    coords.push_back({-1, 1});
    coords.push_back({1, 1});
    coords.push_back({1, 0});
    coords.push_back({-1, 0});

    Rectangle rect(coords);
    ASSERT_TRUE(double(rect) == 2);
}

TEST(test_03, Rectangle_methods) {
    vector<pdd> coords;
    coords.push_back({-1, 1});
    coords.push_back({1, 1});
    coords.push_back({1, 0});
    coords.push_back({-1, 0});

    vector<pdd> coords2;
    coords2.push_back({-2, 2});
    coords2.push_back({2, 2});
    coords2.push_back({2, 0});
    coords2.push_back({-2, 0});

    Rectangle rect(coords), rect2(coords2);

    ASSERT_FALSE(rect == rect2);
}

TEST(test_04, Rectangle_methods) {
    vector<pdd> coords;
    coords.push_back({-1, 1});
    coords.push_back({1, 1});
    coords.push_back({1, 0});
    coords.push_back({-1, 0});

    Rectangle rect(coords), rect2 = rect;

    ASSERT_TRUE(rect == rect2);
}
//----------------------Romb tests-----------------------------//


TEST(test_01, Romb_Constructor) {
    vector<pdd> coords;
    coords.push_back({2, 1.5});
    coords.push_back({3, 0});
    coords.push_back({2, -1.5});
    coords.push_back({1, 0});

    Romb romb(coords);
    Romb romb1(coords);
    Romb romb4(romb);
    Romb romb5(romb);
    Romb romb0(move(romb));
    ASSERT_TRUE(romb == romb1 and romb4 == romb5 and romb0 == romb4);
}

TEST(test_02, Romb_Constructor) {
    vector<pdd> coords;
    coords.push_back({-1, 1});
    coords.push_back({1, 1});
    coords.push_back({1, 0});
    coords.push_back({-1, 0});

    ASSERT_ANY_THROW(Romb romb(coords));
}

TEST(test_03, Romb_Constructor) {
    vector<pdd> coords;
    coords.push_back({1, 3});
    coords.push_back({2, 3});
    coords.push_back({3, 0});
    coords.push_back({0, 0});

    ASSERT_ANY_THROW(Romb romb(coords));
}

TEST(test_01, Romb_methods) {
    vector<pdd> coords;
    coords.push_back({2, 1.5});
    coords.push_back({3, 0});
    coords.push_back({2, -1.5});
    coords.push_back({1, 0});

    Romb romb(coords);
    pdd cent = {2, 0};
    ASSERT_TRUE(romb.Center() == cent);
}

TEST(test_02, Romb_methods) {
    vector<pdd> coords;
    coords.push_back({2, 1.5});
    coords.push_back({3, 0});
    coords.push_back({2, -1.5});
    coords.push_back({1, 0});

    Romb romb(coords);
    ASSERT_TRUE(double(romb) == 3);
}

TEST(test_03, Romb_methods) {
    vector<pdd> coords;
    coords.push_back({2, 1.5});
    coords.push_back({3, 0});
    coords.push_back({2, -1.5});
    coords.push_back({1, 0});

    vector<pdd> coords2;
    coords2.push_back({2, 3});
    coords2.push_back({3, 0});
    coords2.push_back({2, -3});
    coords2.push_back({1, 0});

    Romb romb(coords), romb2(coords2);

    ASSERT_FALSE(romb == romb2);
}

TEST(test_04, Romb_methods) {
    vector<pdd> coords;
    coords.push_back({2, 1.5});
    coords.push_back({3, 0});
    coords.push_back({2, -1.5});
    coords.push_back({1, 0});

    Romb romb(coords), romb2 = romb;

    ASSERT_TRUE(romb == romb2);
}
//-----------------Trapeoid tests ------------------------//

TEST(test_01, Trapeoid_Constructor) {
    vector<pdd> coords;
    coords.push_back({1, 3});
    coords.push_back({2, 3});
    coords.push_back({3, 0});
    coords.push_back({0, 0});

    Trapeoid trap(coords);
    Trapeoid trap1(coords);
    Trapeoid trap4(trap);
    Trapeoid trap5(trap);
    Trapeoid trap0(move(trap));
    ASSERT_TRUE(trap == trap1 and trap4 == trap5 and trap0 == trap4);
}

TEST(test_02, Trapeoid_Constructor) {
    vector<pdd> coords;
    coords.push_back({-1, 1});
    coords.push_back({0, 1});
    coords.push_back({0, 0});
    coords.push_back({-1, 0});

    ASSERT_ANY_THROW(Trapeoid trap(coords));
}

TEST(test_03, Trapeoid_Constructor) {
    vector<pdd> coords;
    coords.push_back({-1, 1});
    coords.push_back({1, 1});
    coords.push_back({1, 0});
    coords.push_back({-1, 0});

    ASSERT_ANY_THROW(Trapeoid trap(coords));
}

TEST(test_01, Trapeoid_methods) {
    vector<pdd> coords;
    coords.push_back({1, 3});
    coords.push_back({2, 3});
    coords.push_back({3, 0});
    coords.push_back({0, 0});

    Trapeoid trap(coords);
    cout << trap.Center().first << ' ' << trap.Center().second << endl;
    pdd cent = {1.5, 1.5};
    ASSERT_TRUE(trap.Center() == cent);
}

TEST(test_02, Trapeoid_methods) {
    vector<pdd> coords;
    coords.push_back({1, 3});
    coords.push_back({2, 3});
    coords.push_back({3, 0});
    coords.push_back({0, 0});

    Trapeoid trap(coords);
    ASSERT_TRUE(double(trap) == 6);
}

TEST(test_03, Trapeoid_methods) {
    vector<pdd> coords;
    coords.push_back({1, 3});
    coords.push_back({2, 3});
    coords.push_back({3, 0});
    coords.push_back({0, 0});

    vector<pdd> coords2;
    coords2.push_back({1, 4});
    coords2.push_back({2, 4});
    coords2.push_back({3, 0});
    coords2.push_back({0, 0});

    Trapeoid trap(coords), trap2(coords2);

    ASSERT_FALSE(trap == trap2);
}

TEST(test_04, Trapeoid_methods) {
    vector<pdd> coords;
    coords.push_back({1, 3});
    coords.push_back({2, 3});
    coords.push_back({3, 0});
    coords.push_back({0, 0});

    Trapeoid trap(coords), trap2 = trap;

    ASSERT_TRUE(trap == trap2);
}
//------------------- Array of Figures Tests -------------------//

TEST(test_01, Array_Figures) {
    Array_Figure Figures;
    ASSERT_TRUE(Figures.GetAllArea() == 0);
}

TEST(test_02, Array_Figures) {
    Array_Figure Figures;

    
    vector<pdd> coords_trap;
    coords_trap.push_back({1, 3});
    coords_trap.push_back({2, 3});
    coords_trap.push_back({3, 0});
    coords_trap.push_back({0, 0});

    Trapeoid trap(coords_trap);

    vector<pdd> coords_romb;
    coords_romb.push_back({2, 1.5});
    coords_romb.push_back({3, 0});
    coords_romb.push_back({2, -1.5});
    coords_romb.push_back({1, 0});

    Romb romb(coords_romb);

    vector<pdd> coords_rect;
    coords_rect.push_back({-1, 1});
    coords_rect.push_back({1, 1});
    coords_rect.push_back({1, 0});
    coords_rect.push_back({-1, 0});

    Rectangle rect(coords_rect);

    Figures.Pushback(&trap);
    Figures.Pushback(&romb);
    Figures.Pushback(&rect);

    ASSERT_TRUE(Figures.GetAllArea() == 11);
}

TEST(test_03, Array_Figures) {
    Array_Figure Figures;

    
    vector<pdd> coords_trap;
    coords_trap.push_back({1, 3});
    coords_trap.push_back({2, 3});
    coords_trap.push_back({3, 0});
    coords_trap.push_back({0, 0});

    Trapeoid trap(coords_trap);

    vector<pdd> coords_romb;
    coords_romb.push_back({2, 1.5});
    coords_romb.push_back({3, 0});
    coords_romb.push_back({2, -1.5});
    coords_romb.push_back({1, 0});

    Romb romb(coords_romb);

    vector<pdd> coords_rect;
    coords_rect.push_back({-1, 1});
    coords_rect.push_back({1, 1});
    coords_rect.push_back({1, 0});
    coords_rect.push_back({-1, 0});

    Rectangle rect(coords_rect);

    Figures.Pushback(&trap);
    Figures.Pushback(&romb);
    Figures.Pushback(&rect);
    pdd cent0 = {1.5, 1.5};
    pdd cent1 = {2, 0};
    pdd cent2 = {0, 0.5};
    ASSERT_TRUE(Figures.GetFigureCenter(0) == cent0 and 
    Figures.GetFigureCenter(1) == cent1 and 
    Figures.GetFigureCenter(2) == cent2);
}

TEST(test_04, Array_Figures) {
    Array_Figure Figures;

    
    vector<pdd> coords_trap;
    coords_trap.push_back({1, 3});
    coords_trap.push_back({2, 3});
    coords_trap.push_back({3, 0});
    coords_trap.push_back({0, 0});

    Trapeoid trap(coords_trap);

    vector<pdd> coords_romb;
    coords_romb.push_back({2, 1.5});
    coords_romb.push_back({3, 0});
    coords_romb.push_back({2, -1.5});
    coords_romb.push_back({1, 0});

    Romb romb(coords_romb);

    vector<pdd> coords_rect;
    coords_rect.push_back({-1, 1});
    coords_rect.push_back({1, 1});
    coords_rect.push_back({1, 0});
    coords_rect.push_back({-1, 0});

    Rectangle rect(coords_rect);

    Figures.Pushback(&trap);
    Figures.Pushback(&romb);
    Figures.Pushback(&rect);
    size_t first = Figures.GetSize();
    Figures.DeleteToIndex(0);
    ASSERT_TRUE(first == Figures.GetSize() + 1);
}

TEST(test_05, Array_Figures) {
    Array_Figure Figures;

    
    vector<pdd> coords_trap;
    coords_trap.push_back({1, 3});
    coords_trap.push_back({2, 3});
    coords_trap.push_back({3, 0});
    coords_trap.push_back({0, 0});

    Trapeoid trap(coords_trap);

    vector<pdd> coords_romb;
    coords_romb.push_back({2, 1.5});
    coords_romb.push_back({3, 0});
    coords_romb.push_back({2, -1.5});
    coords_romb.push_back({1, 0});

    Romb romb(coords_romb);

    vector<pdd> coords_rect;
    coords_rect.push_back({-1, 1});
    coords_rect.push_back({1, 1});
    coords_rect.push_back({1, 0});
    coords_rect.push_back({-1, 0});

    Rectangle rect(coords_rect);

    Figures.Pushback(&trap);
    Figures.Pushback(&romb);
    Figures.Pushback(&rect);
    double area = Figures.GetAllArea();
    Figures.DeleteToIndex(0);
    ASSERT_TRUE(area == Figures.GetAllArea() + double(trap));
}

TEST(test_06, Array_Figures) {
    Array_Figure Figures;

    
    vector<pdd> coords_trap;
    coords_trap.push_back({1, 3});
    coords_trap.push_back({2, 3});
    coords_trap.push_back({3, 0});
    coords_trap.push_back({0, 0});

    Trapeoid trap(coords_trap);

    vector<pdd> coords_romb;
    coords_romb.push_back({2, 1.5});
    coords_romb.push_back({3, 0});
    coords_romb.push_back({2, -1.5});
    coords_romb.push_back({1, 0});

    Romb romb(coords_romb);

    vector<pdd> coords_rect;
    coords_rect.push_back({-1, 1});
    coords_rect.push_back({1, 1});
    coords_rect.push_back({1, 0});
    coords_rect.push_back({-1, 0});

    Rectangle rect(coords_rect);

    Figures.Pushback(&trap);
    Figures.Pushback(&romb);
    Figures.Pushback(&rect);
    double area = Figures.GetAllArea();
    Figures.DeleteToIndex(0);
    ASSERT_FALSE(area == Figures.GetAllArea());
}

TEST(test_07, Array_Figures) {
    Array_Figure Figures;

    
    vector<pdd> coords_trap;
    coords_trap.push_back({1, 3});
    coords_trap.push_back({2, 3});
    coords_trap.push_back({3, 0});
    coords_trap.push_back({0, 0});

    Trapeoid trap(coords_trap);

    vector<pdd> coords_romb;
    coords_romb.push_back({2, 1.5});
    coords_romb.push_back({3, 0});
    coords_romb.push_back({2, -1.5});
    coords_romb.push_back({1, 0});

    Romb romb(coords_romb);

    vector<pdd> coords_rect;
    coords_rect.push_back({-1, 1});
    coords_rect.push_back({1, 1});
    coords_rect.push_back({1, 0});
    coords_rect.push_back({-1, 0});

    Rectangle rect(coords_rect);

    Figures.Pushback(&trap);
    Figures.Pushback(&romb);
    Figures.Pushback(&rect);
    double area = Figures.GetAllArea();
    Figures.DeleteToIndex(0);
    Figures.DeleteToIndex(0);
    Figures.DeleteToIndex(0);
    ASSERT_TRUE(Figures.GetAllArea() == 0);
}