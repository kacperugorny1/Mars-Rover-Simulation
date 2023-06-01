#include "doctest/doctest.h"
#include "Rover.hh"
#include "Kolory.hh"
#include "Vectors.hh"


TEST_CASE("1.Poruszanie sie normalny zakres"){
    Rover x("../bryly_wzorcowe/szescian3.dat","FSR",Kolor_JasnoNiebieski,{20,20,10},{0,0,0},0,30 ,1000);
    double tab[3]  = {0,100,0};
    Vector3D Wynik(tab);
    Vector3D z;
    x.MoveRover(100);
    CHECK(x.returnPosition()==Wynik);
}
TEST_CASE("2.Poruszanie sie duzy zakres"){
    Rover x("../bryly_wzorcowe/szescian3.dat","FSR",Kolor_JasnoNiebieski,{20,20,10},{0,0,0},0,30 ,1000);
    double tab[3]  = {0,4325,0};
    Vector3D Wynik(tab);
    Vector3D z;
    x.MoveRover(4325);
    CHECK(x.returnPosition()==Wynik);
}
TEST_CASE("3.Poruszanie sie maly zakres"){
    Rover x("../bryly_wzorcowe/szescian3.dat","FSR",Kolor_JasnoNiebieski,{20,20,10},{0,0,0},0,30 ,1000);
    double tab[3]  = {0,3,0};
    Vector3D Wynik(tab);
    Vector3D z;
    x.MoveRover(3);
    CHECK(x.returnPosition()==Wynik);
}
TEST_CASE("4.Poruszanie sie bardzo maly zakres"){
    Rover x("../bryly_wzorcowe/szescian3.dat","FSR",Kolor_JasnoNiebieski,{20,20,10},{0,0,0},0,30 ,1000);
    double tab[3]  = {0,0.02,0};
    Vector3D Wynik(tab);
    Vector3D z;
    x.MoveRover(0.02);
    CHECK(x.returnPosition()==Wynik);
}

TEST_CASE("5.Poruszanie sie o 0"){
    Rover x("../bryly_wzorcowe/szescian3.dat","FSR",Kolor_JasnoNiebieski,{20,20,10},{0,0,0},0,30 ,1000);
    double tab[3]  = {0,0,0};
    Vector3D Wynik(tab);
    Vector3D z;
    x.MoveRover(0);
    CHECK(x.returnPosition()==Wynik);
}
TEST_CASE("4.Poruszanie sie ujemna wartosc"){
    Rover x("../bryly_wzorcowe/szescian3.dat","FSR",Kolor_JasnoNiebieski,{20,20,10},{0,0,0},0,30 ,1000);
    double tab[3]  = {0,-15,0};
    Vector3D Wynik(tab);
    Vector3D z;
    x.MoveRover(-15);
    CHECK(x.returnPosition()==Wynik);
}

TEST_CASE("6.Obracanie sie normalny kat"){
    Rover x("../bryly_wzorcowe/szescian3.dat","FSR",Kolor_JasnoNiebieski,{20,20,10},{0,0,0},0,30 ,1000);
    x.RotateRover(30);
    CHECK(x.returnAngle()==30);
}


TEST_CASE("7.Obracanie sie duzy kat"){
    Rover x("../bryly_wzorcowe/szescian3.dat","FSR",Kolor_JasnoNiebieski,{20,20,10},{0,0,0},0,30 ,1000);
    x.RotateRover(2934);
    CHECK(x.returnAngle()==54);
}


TEST_CASE("8.Obracanie sie maly kat"){
    Rover x("../bryly_wzorcowe/szescian3.dat","FSR",Kolor_JasnoNiebieski,{20,20,10},{0,0,0},0,30 ,1000);
    x.RotateRover(3);
    CHECK(x.returnAngle()==3);
}

TEST_CASE("9.Obracanie sie bardzo maly kat"){
    Rover x("../bryly_wzorcowe/szescian3.dat","FSR",Kolor_JasnoNiebieski,{20,20,10},{0,0,0},0,30 ,1000);
    x.RotateRover(0.01);
    CHECK(x.returnAngle()==0.01);
}

TEST_CASE("10.Obracanie sie kat = 0"){
    Rover x("../bryly_wzorcowe/szescian3.dat","FSR",Kolor_JasnoNiebieski,{20,20,10},{0,0,0},0,30 ,1000);
    x.RotateRover(0);
    CHECK(x.returnAngle()==0);
}
TEST_CASE("11.Zlozenie obrot ruch"){
    Rover x("../bryly_wzorcowe/szescian3.dat","FSR",Kolor_JasnoNiebieski,{20,20,10},{0,0,0},0,30 ,1000);
    x.RotateRover(90);
    double tab[3]  = {-15,0,0};
    Vector3D Wynik(tab);
    Vector3D z;
    x.MoveRover(15);
    CHECK(x.returnPosition()==Wynik);
}

TEST_CASE("12.Zlozenie obrot ruch"){
    Rover x("../bryly_wzorcowe/szescian3.dat","FSR",Kolor_JasnoNiebieski,{20,20,10},{0,0,0},0,30 ,1000);
    x.RotateRover(180);
    double tab[3]  = {0,-15,0};
    Vector3D Wynik(tab);
    Vector3D z;
    x.MoveRover(15);
    CHECK(x.returnPosition()==Wynik);
}