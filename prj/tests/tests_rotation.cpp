#include "doctest/doctest.h"
#include "Matrix3D.hh"
#include "Vectors.hh"

TEST_CASE("ROTx1"){
    Matrix3D x;
    double tab[3] = {1,0,0};
    tVector<double,3> z(tab),wynik;
    x.FillRotationX(90);
    wynik = x*z;
    CHECK(z==wynik);
}
TEST_CASE("ROTx2"){
    Matrix3D x;
    double tab[3] = {0,1,0},w[3] = {0,0,1};
    tVector<double,3> z(tab),wynik(w);
    x.FillRotationX(90);
    z = x*z;
    CHECK(z==wynik);
}
TEST_CASE("ROTy1"){
  Matrix3D x;
  double tab[3] = {0,1,0};
  tVector<double,3> z(tab),wynik;
  x.FillRotationY(90);
  wynik = x*z;
  CHECK(z==wynik);
}
TEST_CASE("ROTy2"){
    Matrix3D x;
    double tab[3] = {2,1,1},w[3] = {1,1,-2};
    tVector<double,3> z(tab),wynik(w);
    x.FillRotationY(90);
    z = x*z;
    CHECK(z==wynik);
}
TEST_CASE("ROTz1"){
  Matrix3D x;
  double tab[3] = {0,0,1};
  tVector<double,3> z(tab),wynik;
  x.FillRotationZ(90);
  wynik = x*z;
  CHECK(z==wynik);
}
TEST_CASE("ROTz2"){
    Matrix3D x;
    double tab[3] = {2,11,1},w[3] = {-11,2,1};
    tVector<double,3> z(tab),wynik(w);
    x.FillRotationZ(90);
    z = x*z;
    CHECK(z==wynik);
}