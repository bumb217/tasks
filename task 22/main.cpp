#include<iostream>
#include<vector>
using namespace std;

#define CATCH_CONFIG_MAIN
#include "catch.h"

#include "garden.h"

TEST_CASE("Check plants")
{
    AppleTree apple;
    CherryTree cherry;
    LemonTree lemon;
    PearTree pear;
    
    Visitor Tom;
    
    string on_check = Tom.visit(&apple);
    REQUIRE(on_check == "Checking apple tree.");
    
    on_check = Tom.visit(&pear);
    REQUIRE(on_check == "Checking pear tree.");
    
    on_check = Tom.visit(&lemon);
    REQUIRE(on_check == "Checking lemon tree.");
    
    on_check = Tom.visit(&cherry);
    REQUIRE(on_check == "Checking cherry tree.");
}

TEST_CASE("Visiting plants")
{
    AppleTree apple;
    CherryTree cherry;
    LemonTree lemon;
    PearTree pear;
    
    Visitor John;
    
    apple.accept(&John);
    REQUIRE(apple.visited == true);
    
    cherry.accept(&John);
    REQUIRE(apple.visited == true);
    
    lemon.accept(&John);
    REQUIRE(apple.visited == true);
    
    pear.accept(&John);
    REQUIRE(apple.visited == true);
}

TEST_CASE("Visiting garden")
{
    Garden garden;
    Visitor Jack;
    garden.accept(&Jack);
    REQUIRE(garden.visited == true);
    
    for (GardenPlant* x: garden.getPlants()) {
        REQUIRE(x->visited==true);
    }
}
