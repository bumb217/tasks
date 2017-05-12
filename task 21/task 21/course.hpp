//
//  course.hpp
//  task 21
//
//  Created by Андрей Пригода on 11.05.17.
//  Copyright © 2017 Андрей Пригода. All rights reserved.
//

#ifndef course_hpp
#define course_hpp

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

class Student;
class Teacher;

class Course
{
    int id;
    string title;
    
    Teacher* teacher;
    vector<Student*> atendees;
    
public:
    Course(int number, string t, Teacher* prof);

    int getID();
    string getTitle();
    vector<Student*> getAtendees();
    
    void addAtendee(Student* newStudent);
};

#endif /* course_hpp */
