//
//  person.cpp
//  task 21
//
//  Created by Андрей Пригода on 11.05.17.
//  Copyright © 2017 Андрей Пригода. All rights reserved.
//

#include "person.hpp"


Person::Person(string n, int years, string gender) {
    this->name = n;
    this->age = years;
    this->sex = gender;
}


string Person::getName() {
    return name;
}

int Person::getAge() {
    return age;
}

string Person::getSex() {
    return sex;
}
