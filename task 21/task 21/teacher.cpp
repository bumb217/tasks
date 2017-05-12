//
//  teacher.cpp
//  task 21
//
//  Created by Андрей Пригода on 11.05.17.
//  Copyright © 2017 Андрей Пригода. All rights reserved.
//
#include "teacher.hpp"
#include "course.hpp"
#include "student.hpp"

void Teacher::addCourse(Course* newCourse) {
    my_courses.push_back(newCourse);
}

vector<Course*> Teacher::whatTeaches() {
    return my_courses;
}

void Teacher::asess(Student* student, Course* course, int points) {
    
    mark total;
    total.points = points;
    total.course = course;
    
    student->receiveMark(total);
}
