//
//  person.hpp
//  task 21
//
//  Created by Андрей Пригода on 11.05.17.
//  Copyright © 2017 Андрей Пригода. All rights reserved.
//
#ifndef person_hpp
#define person_hpp

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

class Person
{
    string name;
    int age;
    string sex;
    
public:
    
    Person(string n, int years, string gender);
    string getName();
    int getAge();
    string getSex();
};

#endif /* person_hpp */
