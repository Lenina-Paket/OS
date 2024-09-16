#include <gtest/gtest.h>
#include "trapeoid.hpp"
#include "romb.hpp"
#include "rectangle.hpp"
#include "array.hpp"
#include "figure.hpp"
#include "array-figure.hpp"

//-------------Rectangle tests------------------------------//

TEST(test_01, Rectangle_Constructor) {
    Array<std::pair<int, int>> coords {{-1, 1}, {1, 1}, {1, 0}, {-1, 0}};

    Rectangle rect(coords);
    Rectangle rect1(coords);
    Rectangle rect4(rect);
    Rectangle rect5(rect);
    Rectangle rect0(std::move(rect));
    ASSERT_TRUE(rect == rect1 and rect4 == rect5 and rect0 == rect4);
}

TEST(test_02, Rectangle_Constructor) {
    Array<std::pair<int, int>> coords{{-1, 1}, {0, 1}, {0, 0}, {-1, 0}};
    ASSERT_ANY_THROW(Rectangle rect(coords));
}

TEST(test_03, Rectangle_Constructor) {
    Array<std::pair<int, int>> coords{{1, 3}, {2, 3}, {3, 0}, {0, 0}};

    ASSERT_ANY_THROW(Rectangle rect(coords));
}


TEST(test_01, Rectangle_methods) {
    Array<std::pair<double, double>> coords {{-1, 1}, {1, 1}, {1, 0}, {-1, 0}};
    Rectangle rect(coords);
    std::pair<double, double> cent = {0, 0.5};
    ASSERT_TRUE(rect.Center() == cent);
}

TEST(test_02, Rectangle_methods) {
    Array<std::pair<double, double>> coords {{-1, 1}, {1, 1}, {1, 0}, {-1, 0}};
    Rectangle rect(coords);
    ASSERT_TRUE(double(rect) == 2);
}

TEST(test_03, Rectangle_methods) {
    Array<std::pair<int, int>> coords {{-1, 1}, {1, 1}, {1, 0}, {-1, 0}};

    Array<std::pair<int, int>> coords2 {{-2, 2}, {2, 2}, {2, 0}, {-2, 0}};

    Rectangle rect(coords), rect2(coords2);

    ASSERT_FALSE(rect == rect2);
}

TEST(test_04, Rectangle_methods) {
    Array<std::pair<int, int>> coords {{-1, 1}, {1, 1}, {1, 0}, {-1, 0}};

    Rectangle rect(coords), rect2 = rect;

    ASSERT_TRUE(rect == rect2);
}
//----------------------Romb tests-----------------------------//


TEST(test_01, Romb_Constructor) {
    Array<std::pair<double, double>> coords{{2, 1.5}, {3, 0}, {2, -1.5}, {1, 0}};
    Romb romb(coords);
    Romb romb1(coords);
    Romb romb4(romb);
    Romb romb5(romb);
    Romb romb0(std::move(romb));
    ASSERT_TRUE(romb == romb1 and romb4 == romb5 and romb0 == romb4);
}

TEST(test_02, Romb_Constructor) {
    Array<std::pair<int, int>> coords {{-1, 1}, {1, 1}, {1, 0}, {-1, 0}};
    ASSERT_ANY_THROW(Romb romb(coords));
}

TEST(test_03, Romb_Constructor) {
    Array<std::pair<int, int>> coords{{1, 3}, {2, 3}, {3, 0}, {0, 0}};

    ASSERT_ANY_THROW(Romb romb(coords));
}

TEST(test_01, Romb_methods) {
    Array<std::pair<double, double>> coords{{2, 1.5}, {3, 0}, {2, -1.5}, {1, 0}};
    Romb romb(coords);
    std::pair<double, double> cent = {2, 0};
    ASSERT_TRUE(romb.Center() == cent);
}

TEST(test_02, Romb_methods) {
    Array<std::pair<double, double>> coords{{2, 1.5}, {3, 0}, {2, -1.5}, {1, 0}};

    Romb romb(coords);
    ASSERT_TRUE(double(romb) == 3);
}

TEST(test_03, Romb_methods) {
    Array<std::pair<double, double>> coords{{2, 1.5}, {3, 0}, {2, -1.5}, {1, 0}};
    Array<std::pair<double, double>> coords2 {{2, 3}, {3, 0}, {2, -3}, {1, 0}};

    Romb romb(coords), romb2(coords2);

    ASSERT_FALSE(romb == romb2);
}

TEST(test_04, Romb_methods) {
    Array<std::pair<double, double>> coords{{2, 1.5}, {3, 0}, {2, -1.5}, {1, 0}};

    Romb romb(coords), romb2 = romb;

    ASSERT_TRUE(romb == romb2);
}
//-----------------Trapeoid tests ------------------------//

TEST(test_01, Trapeoid_Constructor) {
    Array<std::pair<int, int>> coords {{1, 3}, {2, 3}, {3, 0}, {0, 0}};

    Trapeoid trap(coords);
    Trapeoid trap1(coords);
    Trapeoid trap4(trap);
    Trapeoid trap5(trap);
    Trapeoid trap0(std::move(trap));
    ASSERT_TRUE(trap == trap1 and trap4 == trap5 and trap0 == trap4);
}

TEST(test_02, Trapeoid_Constructor) {
    Array<std::pair<int, int>> coords {{-1, 1}, {0, 1}, {0, 0}, {-1, 0}};

    ASSERT_ANY_THROW(Trapeoid trap(coords));
}

TEST(test_03, Trapeoid_Constructor) {
    Array<std::pair<int, int>> coords {{-1, 1}, {1, 1}, {1, 0}, {-1, 0}};

    ASSERT_ANY_THROW(Trapeoid trap(coords));
}

TEST(test_01, Trapeoid_methods) {
    Array<std::pair<double, double>> coords {{1, 3}, {2, 3}, {3, 0}, {0, 0}};
    Trapeoid trap(coords);
   
    std::pair<double, double> cent = {1.5, 1.5};
    ASSERT_TRUE(trap.Center() == cent);
}

TEST(test_02, Trapeoid_methods) {
    Array<std::pair<int, int>> coords {{1, 3}, {2, 3}, {3, 0}, {0, 0}};

    Trapeoid trap(coords);
    ASSERT_TRUE(double(trap) == 6);
}

TEST(test_03, Trapeoid_methods) {
    Array<std::pair<int, int>> coords {{1, 3}, {2, 3}, {3, 0}, {0, 0}};

    Array<std::pair<int, int>> coords2 {{1, 4}, {2, 4}, {3, 0}, {0, 0}};

    Trapeoid trap(coords), trap2(coords2);

    ASSERT_FALSE(trap == trap2);
}

TEST(test_04, Trapeoid_methods) {
    Array<std::pair<int, int>> coords {{1, 3}, {2, 3}, {3, 0}, {0, 0}};

    Trapeoid trap(coords), trap2 = trap;

    ASSERT_TRUE(trap == trap2);
}
//------------------- Array of Figures Tests -------------------//

TEST(test_01, Array_Figures) {
    Array<Figure<int>*> Figures;
    ASSERT_EQ(Figures.GetSize(), 0);
}

TEST(test_02, Array_Figures) {
    
    Array<std::pair<double, double>> coords_trap {{1, 3}, {2, 3}, {3, 0}, {0, 0}};

    Trapeoid trap(coords_trap);

    Array<std::pair<double, double>> coords_romb {{2, 1.5}, {3, 0}, {2, -1.5}, {1, 0}};

    Romb romb(coords_romb);

    Array<std::pair<double, double>> coords_rect {{-1, 1}, {1, 1}, {1, 0}, {-1, 0}};

    Rectangle rect(coords_rect);

    Array<Figure<double>*> Figures {&trap, &romb, &rect};
    
    ASSERT_TRUE(GetAllArea(Figures) == 11);
}

TEST(test_03, Array_Figures) {
    
    Array<std::pair<double, double>> coords_trap {{1, 3}, {2, 3}, {3, 0}, {0, 0}};

    Trapeoid trap(coords_trap);

    Array<std::pair<double, double>> coords_romb {{2, 1.5}, {3, 0}, {2, -1.5}, {1, 0}};

    Romb romb(coords_romb);

    Array<std::pair<double, double>> coords_rect {{-1, 1}, {1, 1}, {1, 0}, {-1, 0}};

    Rectangle rect(coords_rect);

    Array<Figure<double>*> Figures {&trap, &romb, &rect};

    std::pair<double, double> cent = {2, 0};

    
    ASSERT_TRUE(Figures[1]->Center() == cent);
}

TEST(test_04, Array_Figures) {
    
    Array<std::pair<double, double>> coords_trap {{1, 3}, {2, 3}, {3, 0}, {0, 0}};

    Trapeoid trap(coords_trap);

    Array<std::pair<double, double>> coords_romb {{2, 1.5}, {3, 0}, {2, -1.5}, {1, 0}};

    Romb romb(coords_romb);

    Array<std::pair<double, double>> coords_rect {{-1, 1}, {1, 1}, {1, 0}, {-1, 0}};

    Rectangle rect(coords_rect);

    Array<Figure<double>*> Figures {&trap, &romb, &rect};

    double area = 6;

    ASSERT_TRUE(double(*Figures[0]) == area);
}



TEST(test_05, Array_Figures) {
    Array<std::pair<double, double>> coords_trap {{1, 3}, {2, 3}, {3, 0}, {0, 0}};

    Trapeoid trap(coords_trap);

    Array<std::pair<double, double>> coords_romb {{2, 1.5}, {3, 0}, {2, -1.5}, {1, 0}};

    Romb romb(coords_romb);

    Array<std::pair<double, double>> coords_rect {{-1, 1}, {1, 1}, {1, 0}, {-1, 0}};

    Rectangle rect(coords_rect);

    Array<Figure<double>*> Figures {&trap, &romb, &rect};

    Figures.Pushback(&trap);
    Figures.Pushback(&romb);
    Figures.Pushback(&rect);

    size_t first = Figures.GetSize();
    Figures.DeleteToIndex(0);
    ASSERT_TRUE(first == Figures.GetSize() + 1);
}

TEST(test_06, Array_Figures) {
    Array<std::pair<double, double>> coords_trap {{1, 3}, {2, 3}, {3, 0}, {0, 0}};

    Trapeoid trap(coords_trap);

    Array<std::pair<double, double>> coords_romb {{2, 1.5}, {3, 0}, {2, -1.5}, {1, 0}};

    Romb romb(coords_romb);

    Array<std::pair<double, double>> coords_rect {{-1, 1}, {1, 1}, {1, 0}, {-1, 0}};

    Rectangle rect(coords_rect);

    Array<Figure<double>*> Figures {&trap, &romb, &rect};

    Figures.Pushback(&trap);
    Figures.Pushback(&romb);
    Figures.Pushback(&rect);
    double area = GetAllArea(Figures);
    Figures.DeleteToIndex(0);
    ASSERT_TRUE(area == GetAllArea(Figures) + double(trap));
}

TEST(test_07, Array_Figures) {
    Array<std::pair<double, double>> coords_trap {{1, 3}, {2, 3}, {3, 0}, {0, 0}};

    Trapeoid trap(coords_trap);

    Array<std::pair<double, double>> coords_romb {{2, 1.5}, {3, 0}, {2, -1.5}, {1, 0}};

    Romb romb(coords_romb);

    Array<std::pair<double, double>> coords_rect {{-1, 1}, {1, 1}, {1, 0}, {-1, 0}};

    Rectangle rect(coords_rect);

    Array<Figure<double>*> Figures {&trap, &romb, &rect};

    Figures.Pushback(&trap);
    Figures.Pushback(&romb);
    Figures.Pushback(&rect);
    double area = GetAllArea(Figures);
    Figures.DeleteToIndex(0);
    ASSERT_FALSE(area == GetAllArea(Figures));
}

TEST(test_08, Array_Figures) {
    Array<std::pair<double, double>> coords_trap {{1, 3}, {2, 3}, {3, 0}, {0, 0}};

    Trapeoid trap(coords_trap);

    Array<std::pair<double, double>> coords_romb {{2, 1.5}, {3, 0}, {2, -1.5}, {1, 0}};

    Romb romb(coords_romb);

    Array<std::pair<double, double>> coords_rect {{-1, 1}, {1, 1}, {1, 0}, {-1, 0}};

    Rectangle rect(coords_rect);

    Array<Figure<double>*> Figures{&trap, &romb, &rect};

    double area = GetAllArea(Figures);
    Figures.DeleteToIndex(0);
    Figures.DeleteToIndex(0);
    Figures.DeleteToIndex(0);
    ASSERT_TRUE(GetAllArea(Figures) == 0);
}