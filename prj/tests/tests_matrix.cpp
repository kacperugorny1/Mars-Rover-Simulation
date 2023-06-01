#include "doctest/doctest.h"
#include "matrix.hh"
#include "Matrix3D.hh"
#include <iostream>
#include <sstream>

TEST_CASE("tMATRIX  Operator >>"){
    tMatrix<double,3> x;
    std::istringstream in("1 2 3 4 5 6 7 8 9");
    in>>x;
    CHECK(in.fail()==false);
}
TEST_CASE("tMATRIX  Operator >>"){
    tMatrix<double,3> x;
    std::istringstream in("1 1 2 5 2 4 0 -3 1");
    std::ostringstream out;
    in>>x;
    out<<x;
    CHECK("| 1 | | 5 | | 0 | | 1 | | 2 | | -3 | | 2 | | 4 | | 1 | "==out.str());
}

TEST_CASE("1.tMatrix::Determinant()"){
    double tab[3][3]={1,1,2,5,2,4,0,-3,1};
    tMatrix<double,3> x(tab);
    CHECK(x.determinant()==-21);
}

TEST_CASE("2.tMatrix::Determinant()"){
    double tab[3][3]={-1,3,1,2,-1,-2,1,2,3};
    tMatrix<double,3> x(tab);
    CHECK(x.determinant()==-20);
}

TEST_CASE("3.tMatrix::Determinant()"){
    double tab[3][3]={12,6,3,6,4,2,-4,4,8};
    tMatrix<double,3> x(tab);
    CHECK(x.determinant()==72);
}
TEST_CASE("4.tMatrix::Determinant()"){
    double tab[3][3]={12,6,3,0,0,0,-4,4,8};
    tMatrix<double,3> x(tab);
    CHECK(x.determinant()==0);
}
TEST_CASE("5.tMatrix::transpose"){
    bool success = true;
    double tab[3][3]={12,6,3,6,4,2,-4,4,8};
    double tab1[3][3] = {12,6,-4,6,4,4,3,2,8};
    tMatrix<double,3> x(tab);
    x.transpose();
    tMatrix<double,3> y(tab1);
    for(int i=0;i<3;++i)
        for(int j=0;j<3;++j)
            if(x(i,j)!=y(i,j))
                success=false;
    CHECK(success);
}

TEST_CASE("6.tMatrix::swap_column"){
    bool success = true;
    double tab[3][3]={12,6,3,6,4,2,-4,4,8};
    double tab1[3][3] = {12,3,6,6,2,4,-4,8,4};
    tMatrix<double,3> x(tab);
    tMatrix<double,3> y(tab1);
    x.swap_column(1,2);
    for(int i=0;i<3;++i)
        for(int j=0;j<3;++j)
            if(x(i,j)!=y(i,j))
                success=false;
    CHECK(success);
}

TEST_CASE("7.tMatrix::insert_row"){
    bool success = true;
    double tab2[3]={2,2,2};
    tVector<double,3> z(tab2);
    double tab[3][3]={12,6,3,6,4,2,-4,4,8};
    double tab1[3][3] = {12,6,3,6,4,2,2,2,2};
    tMatrix<double,3> x(tab);
    tMatrix<double,3> y(tab1);
    x.insert_row(2,z);
    for(int i=0;i<3;++i)
        for(int j=0;j<3;++j)
            if(x(i,j)!=y(i,j))
                success=false;
    CHECK(success);
}
TEST_CASE("8.tMatrix::FrobeniusNorm()"){
    double tab[3][3]={12,6,3,6,4,2,-4,4,8};
    tMatrix<double,3> x(tab);
    CHECK(x.FrobeniusNorm()==sqrt(341));
}