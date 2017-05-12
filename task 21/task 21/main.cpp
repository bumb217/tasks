//
//  main.cpp
//  task 21
//
//  Created by Андрей Пригода on 11.05.17.
//  Copyright © 2017 Андрей Пригода. All rights reserved.
//

#include <iostream>

#define CATCH_CONFIG_MAIN
#include "catch.h"

#include "person.hpp"
#include "course.hpp"
#include "student.hpp"
#include "teacher.hpp"

TEST_CASE("Teacher + Course") {
    Teacher Smith("John Smith", 39, "male");
    Course Bio(11, "Bio", &Smith );
    
    REQUIRE(Bio.getID() == 11);
    REQUIRE(Smith.whatTeaches().size() == 1);
    REQUIRE(Smith.whatTeaches()[0]->getTitle() == "Bio");
}

TEST_CASE("Student test") {
    Teacher Obama("Barack Obama", 46, "male");
    Course English(13, "English", &Obama );
    
    Student Jerry("Tom Jerry", 19, "male");
    
    Jerry.takeCourse(&English);
    Obama.asess(&Jerry, &English, 96);
    
    REQUIRE(English.getAtendees().size() == 1);
    REQUIRE(Jerry.getMarks().size() == 1);
    REQUIRE(Jerry.getMarks()[0].points == 96);
    REQUIRE(Jerry.getMarks()[0].course == &English);
}
