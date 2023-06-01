#include "doctest/doctest.h"
#include "Scene.hh"
#include "Kolory.hh"
#include <string>

TEST_CASE("1.Scena"){
    Scene Test;
    CHECK(Test.Rover_name()=="Simple_Fetch_Rover");
}

TEST_CASE("2.Scena wybor lazika"){
    Scene Test;
    Test.SelectRover(2);
    CHECK(Test.Rover_name()=="Perseverance");
}

TEST_CASE("3.Scena wybor lazika"){
    Scene Test;
    Test.SelectRover(3);
    CHECK(Test.Rover_name()=="Curiosity");
}