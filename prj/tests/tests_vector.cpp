#include "doctest/doctest.h"
#include "vector.hh"



TEST_CASE("1.Overload [] and Constructor")
{
  tVector<double,3> x;
  CHECK(x[0] == 0);
}

TEST_CASE("2.Overload * vector*vector"){
  double result,tab1[3]={2,3,1},tab2[3]={2,2,2};
  tVector<double,3> x(tab1),y(tab2);
  result = x*y;
  CHECK(result==12);
}

TEST_CASE("3.Overload * vector*double"){
  bool success=true;
  double tab1[3]={2,3,1},tab2[3]={4,6,2};
  tVector<double,3> x(tab1),y(tab2);
  x=x*2;
  for(int i = 0; i<3; ++i)
    if(x[i]!=y[i])
      success=false;
  CHECK(success);
}
TEST_CASE("4.Overload + vector+vector"){
  bool success=true;
  double tab1[3]={2,3,1},tab2[3]={4,6,2};
  tVector<double,3> x(tab1),y(tab2);
  x=x+y;
  if(x[0]!=6||x[1]!=9||x[2]!=3)
    success = false;
  CHECK(success);
}