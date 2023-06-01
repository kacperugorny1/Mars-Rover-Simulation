#include "doctest/doctest.h"
#include "Contour.hh"

TEST_CASE("1.Przecinanie sie obrysow"){
    Contour x({1,1},{2,2});
    Contour y({1,2},{2,3});

    CHECK(x.IsImposed(y));
}
TEST_CASE("2.Przecinanie sie obrysow"){
    Contour x({1,1},{2,2});
    Contour y({0,2},{1,3});

    CHECK(x.IsImposed(y));
}
TEST_CASE("3.Przecinanie sie obrysow"){
    Contour x({1,1},{2,3});
    Contour y({1,2},{3,4});

    CHECK(x.IsImposed(y));
}
TEST_CASE("4.Przecinanie sie obrysow"){
    Contour x({2,2},{4,4});
    Contour y({1,1},{3,3});

    CHECK(x.IsImposed(y));
}
TEST_CASE("5.Przecinanie sie obrysow"){
    Contour x({-7,-4},{-5,-3});
    Contour y({-8,-6},{-5,-4});

    CHECK(x.IsImposed(y));
}
TEST_CASE("6.Przecinanie sie obrysow"){
    Contour x({-2,-3},{0,5});
    Contour y({-1,-2},{2,1});

    CHECK(x.IsImposed(y));
}
TEST_CASE("7.Nie przecinaja sie obrysy"){
    Contour x({-2,-3},{-1,-2});
    Contour y({0,0},{2,1});

    CHECK(!x.IsImposed(y));
}

TEST_CASE("8.Nie przecinaja sie obrysy"){
    Contour x({-1,-1},{0,0.92});
    Contour y({0,1},{2,1});

    CHECK(!x.IsImposed(y));
}