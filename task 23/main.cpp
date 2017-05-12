#include <iostream>
#include <string>
#include <vector>

#include "mediator.h"
#include "collegue.h"

using namespace std;

#define CATCH_CONFIG_MAIN
#include "catch.h"

TEST_CASE("Chat number")
{
    Mediator* med = new DogsChatSystem(23);
    REQUIRE(med->number == 23);
}

TEST_CASE("New Dog")
{
    Mediator* med = new DogsChatSystem(23);
    Dog newD("Princess", 3, med);
    REQUIRE(newD.name == "Princess");
    REQUIRE(newD.age == 3);
    REQUIRE(newD.messages.empty() == true);
}

TEST_CASE("Chatting")
{
    Mediator* med = new DogsChatSystem(23);
    Dog first("Princess", 3, med);
    Dog second("Tom", 5, med);
    Dog third("Kitty", 1, med);
    
    first.sendInfo("Hello!");
    second.sendInfo("Wow, pretty, how r u?");
    first.sendInfo("Nice");
    
    REQUIRE(first.messages.size() == 2);
    REQUIRE(second.messages.size() == 1);
    
    REQUIRE(first.messages[0] == "Hello!");
    REQUIRE(second.messages[0] == "Wow, pretty, how r u?");
    REQUIRE(first.messages[1] == "Nice");
}
