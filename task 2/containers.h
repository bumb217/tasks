//
//  containers.h
//  task-2
//
//  Created by Андрей Пригода on 27.03.17.
//  Copyright © 2017 Андрей Пригода. All rights reserved.
//

#ifndef _CONTAINERS_
#define _CONTAINERS_

#include <vector>
using namespace std;

// Container interface
template <class T>
class Container {
public:
#pragma region Iterator interface
    class iterator {
    public:
        virtual void first() = 0;
        virtual bool isDone() = 0;
        virtual void operator++() = 0;
        virtual T& operator*() = 0;
        
        virtual bool operator!=(iterator& another) = 0;
        virtual bool operator==(iterator& another) = 0;
    };
#pragma endregion
    
#pragma region Container methods
    virtual iterator& begin() = 0;
    virtual iterator& end() = 0;
    
    virtual unsigned int size() = 0;
    
    virtual void insert(iterator &insBefore, const T& elem) = 0;
    virtual void erase(iterator &toDelete) = 0;
    
#pragma endregion
    
};

// Adapter for STL
template<class T, class STL = std::vector<T>>
class STLAdapter: public Container<T> {
    
    friend class AdaptedIterator;
    
    class AdaptedIterator: public iterator {
        friend class STLAdapter;
        
        typename STL::iterator *cur;
        typename STLAdapter<T, STL> *parent;
        
        // Constructor
        AdaptedIterator(STLAdapter *vec){
            cur = NULL;
            parent = vec;
        };
        
    public:
        
        void first() {
            auto it = parent->elements.begin();
            cur = new STL::iterator(it);
        }
        bool isDone() {
            auto a = *cur;
            auto b = parent->elements.end();
            return (a == b);
        }
        void operator++() {
            cur->operator++();
        }
        T& operator*() {
            return cur->operator*();
        }
        
        bool operator!=(iterator& another) {
            
            auto &rval = static_cast<AdaptedIterator&>(another);
            return (*cur != *rval.cur);
        }
        bool operator==(iterator& another) {
            return !(this->operator!=(another));
        }
    };
    
    STL elements;
    unsigned int len;
    
public:
    STLAdapter():len(0){};
    
    AdaptedIterator &begin() {
        AdaptedIterator *res = new AdaptedIterator(this);
        res->first();
        return (*res);
    }
    AdaptedIterator &end() {
        AdaptedIterator *res = new AdaptedIterator(this);
        res->first();
        while (! (res->isDone())) {
            res->operator++();
        }
        
        return (*res);
    }
    
    void insert(iterator &insBefore, const T& elem) {
        auto &toIns = static_cast<AdaptedIterator&>(insBefore);
        
        auto Iterator = *toIns.cur;
        auto &parentObj = (*toIns.parent);
        
        Iterator = parentObj.elements.emplace(Iterator, elem);
        
        toIns.cur = new STL::iterator(Iterator);
        ++len;
    }
    void erase(iterator &toDelete) {
        auto &toDel = static_cast<AdaptedIterator&>(toDelete);
        
        auto Iterator = *toDel.cur;
        auto &parentObj = (*toDel.parent);
        
        Iterator = parentObj.elements.erase(Iterator);
        --len;
    }
    
    unsigned int size() {
        return len;
    }
};	

#endif
