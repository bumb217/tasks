//
//  student.cpp
//  task 21
//
//  Created by Андрей Пригода on 11.05.17.
//  Copyright © 2017 Андрей Пригода. All rights reserved.
//
#include "student.hpp"
#include "course.hpp"


vector<Course*> Student::getCourses() {
    return courses;
}

vector<mark> Student::getMarks() {
    return marks;
}

void Student::takeCourse(Course* newCourse) {
    courses.push_back(newCourse);
    
    newCourse->addAtendee(this);
}

void Student::receiveMark(mark newMark) {
    marks.push_back(newMark);
}

