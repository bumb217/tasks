#ifndef mediator_h
#define mediator_h

#include <string>

class Dog;

class Mediator
{
public:
    virtual void chat(Dog* coll, std::string message) = 0;
     int number;
};

class DogsChatSystem : public Mediator
{
public:
    DogsChatSystem(int n);
    void chat(Dog* coll, std::string message);
};

#endif /* mediator_h */
