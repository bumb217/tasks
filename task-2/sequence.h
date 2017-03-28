//
//  sequence.h
//  task-2
//
//  Created by Андрей Пригода on 27.03.17.
//  Copyright © 2017 Андрей Пригода. All rights reserved.
//

#ifndef SEQUENCE_INCLUDED
#define SEQUENCE_INCLUDED

#include <vector>
#include <exception>
#include <iostream>
#include "containers.h"
//
// Class represents sequence of pointers to object
//

template <class T>
class sequence {
    Container<T*> *contents;
    unsigned int sequenceSize;
    
public:
    sequence(Container<T*> *cont = NULL):sequenceSize(0){
        if (cont) contents = cont;
        else contents = new STLAdapter<T*>();
    }
    
    unsigned int size() {return sequenceSize;}
    
    void insert(T* nval, const int &at = 0, const bool &reverse = false);
    void pop(const int &at = 0, const bool &reverse = false);
    T* get(const int &at = 0, const bool &reverse = false);
    
    //
    // Exception classes
    //
    
    class outOfrangeException: public exception {
        void *src;
    public:
        outOfrangeException(void *source):src(source){};
        void printMessage(){
            cout << "Out of range exception at " << src << endl;
        }
    };
};

//
// Sequence implementation
//

template <class T>
void sequence<T>::insert(T* nval, const int &at = 0, const bool &reverse = false) {
    if (at > sequenceSize) throw outOfrangeException(this);
    if (reverse) {
        // If element is added to the end of sequence
        if (at == 0) {
            auto &i = (*contents).end();
            auto &j = (*contents).begin();
            
            //while (++i != (*contents).end()) ++j;
            (*contents).insert(i, nval);
        }
        // Get iterator to position and insert element
        else {
            int index = sequenceSize - at;
            auto &iterator = (*contents).begin();
            for (int i = 0; i < at; i++)
                ++iterator;
            (*contents).insert(iterator, nval);
        }
    }
    else {
        // Get iterator to position and insert element
        auto &iterator = (*contents).begin();
        for (int i = 0; i < at; i++) ++iterator;
        (*contents).insert(iterator, nval);
    }
    ++sequenceSize;
}

template <class T>
void sequence<T>::pop(const int &at = 0, const bool &reverse = false) {
    if (at > sequenceSize) throw outOfrangeException(this);
    if (reverse) {
        int index = sequenceSize - 1 - at;
        auto &iterator = (*contents).begin();
        for (int i = 0; i < index; i++) ++iterator;
        (*contents).erase(iterator);
    }
    else {
        auto &iterator = (*contents).begin();
        for (int i = 0; i < at; i++) ++iterator;
        (*contents).erase(iterator);
    }
    --sequenceSize;
}

template <class T>
T* sequence<T>::get(const int &at = 0, const bool &reverse = false) {
    if (at > sequenceSize) throw outOfrangeException(this);
    if (reverse) {
        int index = sequenceSize - 1 - at;
        
        auto &iterator = (*contents).begin();
        for (int i = 0; i < index; i++) ++iterator;
        
        return (*iterator);
    }
    else {
        
        auto &iterator = (*contents).begin();
        for (int i = 0; i < at; i++) 
            ++iterator;
        
        return (*iterator);
    }
    
}

#endif
