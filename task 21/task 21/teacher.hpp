//
//  teacher.hpp
//  task 21
//
//  Created by Андрей Пригода on 11.05.17.
//  Copyright © 2017 Андрей Пригода. All rights reserved.
//
#ifndef teacher_hpp
#define teacher_hpp

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include "person.hpp"

class Course;
class Student;

class Teacher : public Person
{
    vector<Course*> my_courses;
    
public:
    Teacher(string n, int years, string gender) : Person(n, years, gender) {}
    
    void addCourse(Course* newCourse);
    vector<Course*> whatTeaches();
    void asess(Student* student, Course* course, int points);
    
};

#endif /* teacher_hpp */
