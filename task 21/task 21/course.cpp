//
//  course.cpp
//  task 21
//
//  Created by Андрей Пригода on 11.05.17.
//  Copyright © 2017 Андрей Пригода. All rights reserved.
//

#include "course.hpp"
#include "student.hpp"
#include "teacher.hpp"

Course::Course(int number, string t, Teacher* prof) {
    this->id = number;
    this->title = t;
    this->teacher = prof;
    
    prof->addCourse(this);
}

int Course::getID() {
    return id;
}

string Course::getTitle() {
    return title;
}

vector<Student*> Course::getAtendees() {
    return atendees;
}

void Course::addAtendee(Student* newStudent) {
    atendees.push_back(newStudent);
}
