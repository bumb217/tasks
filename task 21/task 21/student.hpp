//
//  student.hpp
//  task 21
//
//  Created by Андрей Пригода on 11.05.17.
//  Copyright © 2017 Андрей Пригода. All rights reserved.
//

#ifndef student_hpp
#define student_hpp

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include "person.hpp"

using namespace std;

class Course;

struct mark
{
    int points;
    Course* course;
};

class Student : public Person
{
    vector<Course*> courses;
    vector<mark> marks;
    
public:
    Student(string n, int years, string gender) : Person(n, years, gender) {}


    vector<Course*> getCourses();
    vector<mark> getMarks();
    
    void takeCourse(Course* newCourse);
    void receiveMark(mark newMark);
};

#endif /* student_hpp */
